#include <chrono>

#include "servermanager/network/custom/CustomServerNetworkHandler.h"
#include "servermanager/ServerManager.h"
#include "servermanager/BanList.h"
#include "servermanager/BanEntry.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/event/EventFactory.h"
#include "servermanager/event/player/PlayerPreLoginEvent.h"
#include "servermanager/event/player/PlayerLoginEvent.h"
#include "servermanager/event/player/PlayerJoinEvent.h"
#include "servermanager/event/player/PlayerQuitEvent.h"
#include "servermanager/event/player/PlayerChatEvent.h"
#include "servermanager/event/player/PlayerCommandPreprocessEvent.h"
#include "servermanager/event/player/PlayerAnimationEvent.h"
#include "servermanager/event/block/SignChangeEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/block/Block.h"
#include "minecraftpe/gamemode/GameMode.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/LevelStorage.h"
#include "minecraftpe/level/BlockSource.h"
#include "minecraftpe/level/dimension/Dimension.h"
#include "minecraftpe/blockentity/BlockEntity.h"
#include "minecraftpe/network/ServerNetworkHandler.h"
#include "minecraftpe/network/PacketSender.h"
#include "minecraftpe/network/RakNetInstance.h"
#include "minecraftpe/network/protocol/LoginPacket.h"
#include "minecraftpe/network/protocol/TextPacket.h"
#include "minecraftpe/network/protocol/DisconnectPacket.h"
#include "minecraftpe/network/protocol/PlayStatusPacket.h"
#include "minecraftpe/network/protocol/UseItemPacket.h"
#include "minecraftpe/network/protocol/DropItemPacket.h"
#include "minecraftpe/network/protocol/ContainerSetSlotPacket.h"
#include "minecraftpe/network/protocol/BlockEntityDataPacket.h"
#include "minecraftpe/network/protocol/AnimatePacket.h"
#include "minecraftpe/network/protocol/MovePlayerPacket.h"
#include "minecraftpe/SharedConstants.h"
#include "hook/hook.h"
#include "hook/Substrate.h"
#include "log.h"

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, onDisconnect, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, const std::string &message)
{
	for(SMPlayer *player : ServerManager::getOnlinePlayers())
	{
		if(player->getHandle()->guid == guid)
		{
			ServerPlayer *serverPlayer = (ServerPlayer *)player->getHandle();
			if(player->joined)
			{
				real->level->getLevelStorage()->save(*player->getHandle());

				PlayerQuitEvent quitEvent(player, "§e%multiplayer.player.left", {player->getName()});
				ServerManager::getPluginManager()->callEvent(quitEvent);

				TextPacket pk;
				pk.type = TextPacket::TYPE_TRANSLATION;
				pk.message = quitEvent.getQuitMessage();
				pk.params = quitEvent.getQuitParams();
				real->sender->send(pk);

				serverPlayer->disconnect();
				serverPlayer->remove();

				// TODO
				real->raknet->announceServer(ServerManager::getServerName());
			}
			ServerManager::getServer()->removePlayer(serverPlayer);

			break;
		}
	}
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, disconnectClient, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, const std::string &message)
{
	DisconnectPacket pk;
	pk.message = message;
	real->sender->send(guid, pk);

	real->onDisconnect(guid, message);
}

FUNCTION_HOOK_CPP(bool, CustomServerNetworkHandler, allowIncomingPacketId, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, int packetId)
{
	return allowIncomingPacketId_real(real, guid, packetId);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleLogin, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, LoginPacket *packet)
{
	if(!real->visible || real->_getPlayer(guid))
		return;

	if(packet->protocol1 != SharedConstants::NetworkProtocolVersion)
	{
		PlayStatusPacket statusPacket;
		if(packet->protocol1 < SharedConstants::NetworkProtocolVersion)
			statusPacket.status = PlayStatusPacket::LOGIN_FAILED_CLIENT;
		else
			statusPacket.status = PlayStatusPacket::LOGIN_FAILED_SERVER;
		real->sender->send(guid, statusPacket);

		return;
	}

	std::string username = packet->username;
	std::string iusername = SMUtil::toLower(packet->username);
	const char *ipAddress = real->raknet->getPeer()->GetSystemAddressFromGuid(guid).ToString(false);

	PlayerPreLoginEvent preLoginEvent(username, ipAddress, packet->clientUUID);
	ServerManager::getPluginManager()->callEvent(preLoginEvent);
	if(preLoginEvent.getResult() != PlayerPreLoginEvent::ALLOWED)
	{
		real->disconnectClient(guid, preLoginEvent.getKickMessage());
		return;
	}

	bool valid = true;

	int len = username.length();
	if(len > 16 || len < 3)
		valid = false;

	for(int i = 0; i < len; i++)
	{
		char c = username[i];
		if((c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <= 'Z') ||
				(c >= '0' && c <= '9') || c == '_')
			continue;

		valid = false;
		break;
	}

	std::unique_ptr<ServerPlayer> entity = real->createNewPlayer(guid, packet);
	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(entity.get());

	PlayerLoginEvent loginEvent(smPlayer, ipAddress);

	if(!valid || !iusername.compare(SMUtil::toLower(ServerManager::getLocalPlayer()->getName())) ||
			!iusername.compare("rcon") || !iusername.compare("console") || !iusername.compare("server"))
		loginEvent.disallow(PlayerLoginEvent::KICK_INVALID_NAME, "disconnectionScreen.invalidName");
	else if(packet->skin.length() != 64 * 32 * 4 && packet->skin.length() != 64 * 64 * 4)
		loginEvent.disallow(PlayerLoginEvent::KICK_INVALID_SKIN, "disconnectionScreen.invalidSkin");
	else if(ServerManager::getBanList(BanList::NAME)->isBanned(iusername))
	{
		BanEntry *entry = ServerManager::getBanList(BanList::NAME)->getBanEntry(iusername);
		loginEvent.disallow(PlayerLoginEvent::KICK_BANNED, "You are banned from this server! Reason: " + entry->getReason());
	}
	else if(ServerManager::hasWhitelist() && !ServerManager::isWhitelisted(iusername))
		loginEvent.disallow(PlayerLoginEvent::KICK_WHITELIST, "You are not white-listed on this server!");
	else if (ServerManager::getBanList(BanList::IP)->isBanned(ipAddress))
	{
		BanEntry *entry = ServerManager::getBanList(BanList::IP)->getBanEntry(ipAddress);
		loginEvent.disallow(PlayerLoginEvent::KICK_BANNED, "Your IP address is banned from this server! Reason: " + entry->getReason());
	}

	ServerManager::getPluginManager()->callEvent(loginEvent);
	if(loginEvent.getResult() != PlayerLoginEvent::ALLOWED)
	{
		real->disconnectClient(guid, loginEvent.getKickMessage());
		return;
	}
	sendLoginMessageLocal(real, guid, packet, std::move(entity));
}

void CustomServerNetworkHandler::sendLoginMessageLocal(ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, LoginPacket *packet, std::unique_ptr<ServerPlayer> entity)
{
	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(entity.get());

	std::string iusername = SMUtil::toLower(packet->username);
	for(SMPlayer *p : ServerManager::getOnlinePlayers())
	{
		if(p != smPlayer && !SMUtil::toLower(p->getName()).compare(iusername))
		{
			real->disconnectClient(p->getHandle()->guid, "You logged in from another location");
			break;
		}
	}

	PlayStatusPacket pk;
	pk.status = PlayStatusPacket::LOGIN_SUCCESS;
	real->sender->send(guid, pk);

	Dimension *dimension = entity->getDimension();
	if(!dimension)
		dimension = real->level->createDimension(DIMENSION_NORMAL);

	entity->prepareRegion(*dimension->getChunkSource());
	real->_sendLevelData(entity.get(), guid);

	ServerPlayer *player = entity.get();
	real->level->addPlayer(std::move(entity));
	real->_sendAdditionalLevelData(player, guid);

	// TODO
	real->raknet->announceServer(ServerManager::getServerName());

	smPlayer->setAddress(real->raknet->getPeer()->GetSystemAddressFromGuid(guid).ToString(false));
	smPlayer->joined = true;

	PlayerJoinEvent joinEvent(smPlayer, "");
	ServerManager::getPluginManager()->callEvent(joinEvent);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleText, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, TextPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player->isAlive() || packet->type != TextPacket::TYPE_CHAT)
		return;

	std::string message = packet->message;
	if(SMUtil::trim(message).empty() || message.length() >= 255)
		return;

	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(player);
	if(message[0] == '#')
	{
		PlayerCommandPreprocessEvent event(smPlayer, message);
		ServerManager::getPluginManager()->callEvent(event);

		if(event.isCancelled())
			return;

		message = event.getMessage();
		ServerManager::dispatchCommand(event.getPlayer(), message.erase(0, 1));
	}
	else
	{
		PlayerChatEvent event(smPlayer, message);
		ServerManager::getPluginManager()->callEvent(event);

		if(event.isCancelled())
			return;

		message = SMUtil::format(event.getFormat().c_str(), event.getPlayer()->getDisplayName().c_str(), event.getMessage().c_str());
		ServerManager::broadcastMessage(message);
	}
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMoveEntity, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MoveEntityPacket *packet)
{
	handleMoveEntity_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMovePlayer, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MovePlayerPacket *packet)
{
	Player *player = real->_getPlayer(guid, packet->uniqueID);
	if(!player || player->i1 != 0 || player->b4)
		return;

	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(player);

	Location from(smPlayer->getRegion(), player->lastPos, player->lastRotation);
	Location to = smPlayer->getLocation();

	to.setPos(packet->pos);
	to.setRotation(packet->rot);

	PlayerMoveEvent event(smPlayer, from, to);
	ServerManager::getPluginManager()->callEvent(event);

	if(event.isCancelled())
	{
		from.setY(from.getY() + 1.62f);

		MovePlayerPacket pk;
		pk.uniqueID = player->getUniqueID();
		pk.pos = from.getPos();
		pk.rot = from.getRotation();
		pk.yaw = from.getRotation().y;
		pk.mode = MovePlayerPacket::RESET;
		pk.onGround = false;
		real->sender->send(player->guid, pk);
		return;
	}

	if(!to.equals(event.getTo()) && !event.isCancelled())
	{
		smPlayer->teleport(event.getTo(), PlayerTeleportEvent::UNKNOWN);
		return;
	}

	if(!from.equals(smPlayer->getLocation()) && smPlayer->justTeleported)
	{
		smPlayer->justTeleported = false;
		return;
	}

	if(!player->vehicle)
	{
		if(packet->pos.y < -128.0f)
			packet->pos.y = -128.0f;
		else if(packet->pos.y > 512)
			packet->pos.y = 512.0f;

		player->motion.x = 0;
		player->motion.y = 0;
		player->motion.z = 0;

		if(packet->mode != MovePlayerPacket::RESET || (packet->mode == MovePlayerPacket::RESET && player->isAlive()))
		{
			player->_checkMovementStatistiscs(packet->pos - player->pos);
			if(player->b3 || !player->onGround)
				player->lerpTo(packet->pos, packet->rot, 3);
			else
				player->lerpTo(packet->pos, packet->rot, 1);
		}
		player->checkBlockCollisions();
		player->yaw = packet->yaw;
	}
	else
	{
		player->vehicle->positionRider(*player);
		player->normalTick();
		player->pos4.y = 0;
		player->moveTo(player->pos, packet->rot);
		player->yaw = packet->yaw;

		if(player->vehicle)
			player->vehicle->positionRider(*player);

		player->tick(*player->getRegion());
	}
	player->getRegion()->getDimension()->sendBroadcast(*packet, player);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleRemoveBlock, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, RemoveBlockPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player || !player->isAlive())
		return;



	handleRemoveBlock_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleEntityEvent, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, EntityEventPacket *packet)
{
	handleEntityEvent_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMobEquipment, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MobEquipmentPacket *packet)
{
	handleMobEquipment_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMobArmorEquipment, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MobArmorEquipmentPacket *packet)
{
	handleMobArmorEquipment_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleInteract, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, InteractPacket *packet)
{
	handleInteract_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleUseItem, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, UseItemPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player || !player->isAlive())
		return;

	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(player);

	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if(packet->face == 255)
	{
		if(!packet->item.isNull() && packet->item.getId() == smPlayer->lastBlock && smPlayer->lastPacket != 0 && millis - smPlayer->lastPacket < 100)
		{
			smPlayer->lastPacket = 0;
			return;
		}
	}
	else
	{
		smPlayer->lastPacket = millis;
		smPlayer->lastBlock = packet->item.getId();
	}

	if(packet->face == 255)
	{
		std::unique_ptr<PlayerInteractEvent> event = EventFactory::callPlayerInteractEvent(player, Action::RIGHT_CLICK_AIR, player->getSelectedItem());
		if(event->useItemInHand() != Event::DENY)
			real->gamemode->useItem(*player, *player->getSelectedItem());
	}
	else
	{
		if(player->distanceTo(Vec3(packet->pos)) >= 12)
			return;

		Block *touchedBlock = player->getRegion()->getBlock(packet->pos);
		if(touchedBlock->isType(Block::mInvisibleBedrock))
			return;

		if(!player->isSneaking())
		{
			if(touchedBlock->use(*player, packet->pos))
				return;
		}

		Vec3 oldPos = player->pos;
		player->setPos(packet->entityPos);

		real->gamemode->useItemOn(*player, player->getSelectedItem(), packet->pos, packet->face,
			Vec3(packet->pos.x + packet->fPos.x, packet->pos.y + packet->fPos.y, packet->pos.z + packet->fPos.z));

		player->setPos(oldPos);
	}
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handlePlayerAction, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, PlayerActionPacket *packet)
{
	handlePlayerAction_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleDropItem, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, DropItemPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player || !player->isAlive() || !player->getSelectedItem())
		return;

	ItemInstance *item = player->getSelectedItem();
	item->count = packet->item.count;

	player->drop(item, packet->drop);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerClose, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerClosePacket *packet)
{
	handleContainerClose_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerSetSlot, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerSetSlotPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player || !player->isAlive())
		return;

	handleContainerSetSlot_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerSetContent, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerSetContentPacket *packet)
{
	handleContainerSetContent_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleCraftingEvent, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, CraftingEventPacket *packet)
{
	LOGI("handleCraftingEvent");
	handleCraftingEvent_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleAnimate, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, AnimatePacket *packet)
{
	Player *player = real->_getPlayer(guid, packet->uniqueID);
	if(!player || !player->isAlive())
		return;

	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(player);
	if(smPlayer->isLocalPlayer())
		return;

	PlayerAnimationEvent event(smPlayer, (PlayerAnimationType)packet->action);
	ServerManager::getPluginManager()->callEvent(event);

	if(event.isCancelled())
		return;

	handleAnimate_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleBlockEntityData, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, BlockEntityDataPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player)
		return;

	SMPlayer *smPlayer = (SMPlayer *)ServerManager::getEntity(player);
	if(smPlayer->isLocalPlayer())
		return;

	BlockEntity *blockEntity = player->getRegion()->getBlockEntity(packet->pos);
	if(!blockEntity)
		return;

	if(BlockEntity::isType(*blockEntity, BlockEntityType::SIGN) && !packet->dataTag.getString("id").compare("Sign"))
	{
		SignChangeEvent event(player->getRegion()->getBlock(packet->pos), smPlayer, {
			packet->dataTag.getString("Text1"),
			packet->dataTag.getString("Text2"),
			packet->dataTag.getString("Text3"),
			packet->dataTag.getString("Text4")
		});
		ServerManager::getPluginManager()->callEvent(event);

		if(!event.isCancelled())
		{
			blockEntity->onUpdatePacket(packet->dataTag);
			player->getRegion()->getDimension()->sendBroadcast(*packet, player);
		}
	}
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handlePlayerInput, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, PlayerInputPacket *packet)
{
	handlePlayerInput_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleSpawnExperienceOrb, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, SpawnExperienceOrbPacket *packet)
{
	handleSpawnExperienceOrb_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, allowIncomingConnections, ServerNetworkHandler *real, const std::string &name, bool visible)
{
	real->visible = true;
	real->raknet->announceServer(ServerManager::getServer()->getServerName());
}

void CustomServerNetworkHandler::setupHooks()
{
	void **ServerNetworkHandler = GetVtable("_ZTV20ServerNetworkHandler");
	VirtualHook(ServerNetworkHandler, 6, (void *) &onDisconnect, (void **) &onDisconnect_real);
	VirtualHook(ServerNetworkHandler, 7, (void *) &allowIncomingPacketId, (void **) &allowIncomingPacketId_real);
	VirtualHook(ServerNetworkHandler, 9, (void *) &handleLogin, (void **) &handleLogin_real);
	VirtualHook(ServerNetworkHandler, 12, (void *) &handleText, (void **) &handleText_real);
	VirtualHook(ServerNetworkHandler, 22, (void *) &handleMoveEntity, (void **) &handleMoveEntity_real);
	VirtualHook(ServerNetworkHandler, 23, (void *) &handleMovePlayer, (void **) &handleMovePlayer_real);
	VirtualHook(ServerNetworkHandler, 24, (void *) &handleRemoveBlock, (void **) &handleRemoveBlock_real);
	VirtualHook(ServerNetworkHandler, 30, (void *) &handleEntityEvent, (void **) &handleEntityEvent_real);
	VirtualHook(ServerNetworkHandler, 32, (void *) &handleMobEquipment, (void **) &handleMobEquipment_real);
	VirtualHook(ServerNetworkHandler, 33, (void *) &handleMobArmorEquipment, (void **) &handleMobArmorEquipment_real);
	VirtualHook(ServerNetworkHandler, 39, (void *) &handleInteract, (void **) &handleInteract_real);
	VirtualHook(ServerNetworkHandler, 40, (void *) &handleUseItem, (void **) &handleUseItem_real);
	VirtualHook(ServerNetworkHandler, 41, (void *) &handlePlayerAction, (void **) &handlePlayerAction_real);
	VirtualHook(ServerNetworkHandler, 43, (void *) &handleDropItem, (void **) &handleDropItem_real);
	VirtualHook(ServerNetworkHandler, 45, (void *) &handleContainerClose, (void **) &handleContainerClose_real);
	VirtualHook(ServerNetworkHandler, 47, (void *) &handleContainerSetSlot, (void **) &handleContainerSetSlot_real);
	VirtualHook(ServerNetworkHandler, 48, (void *) &handleContainerSetContent, (void **) &handleContainerSetContent_real);
	VirtualHook(ServerNetworkHandler, 50, (void *) &handleCraftingEvent, (void **) &handleCraftingEvent_real);
	VirtualHook(ServerNetworkHandler, 52, (void *) &handleAnimate, (void **) &handleAnimate_real);
	VirtualHook(ServerNetworkHandler, 53, (void *) &handleBlockEntityData, (void **) &handleBlockEntityData_real);
	VirtualHook(ServerNetworkHandler, 54, (void *) &handlePlayerInput, (void **) &handlePlayerInput_real);
	VirtualHook(ServerNetworkHandler, 61, (void *) &handleSpawnExperienceOrb, (void **) &handleSpawnExperienceOrb_real);
	MSHookFunction((void *) &ServerNetworkHandler::allowIncomingConnections, (void **) *allowIncomingConnections, (void **) &allowIncomingConnections_real);
	MSHookFunction((void *) &ServerNetworkHandler::disconnectClient, (void **) &disconnectClient, (void **) &disconnectClient_real);
}
