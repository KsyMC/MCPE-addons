#include "servermanager/network/CustomServerNetworkHandler.h"
#include "servermanager/ServerManager.h"
#include "servermanager/client/resources/BanList.h"
#include "servermanager/client/resources/BanEntry.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/entity/SMLocalPlayer.h"
#include "servermanager/event/player/PlayerJoinEvent.h"
#include "servermanager/event/player/PlayerQuitEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/LevelStorage.h"
#include "minecraftpe/level/BlockSource.h"
#include "minecraftpe/level/dimension/Dimension.h"
#include "minecraftpe/network/ServerNetworkHandler.h"
#include "minecraftpe/network/PacketSender.h"
#include "minecraftpe/network/RakNetInstance.h"
#include "minecraftpe/network/protocol/LoginPacket.h"
#include "minecraftpe/network/protocol/TextPacket.h"
#include "minecraftpe/network/protocol/DisconnectPacket.h"
#include "minecraftpe/network/protocol/PlayStatusPacket.h"
#include "minecraftpe/network/protocol/UseItemPacket.h"
#include "minecraftpe/network/protocol/DropItemPacket.h"
#include "minecraftpe/SharedConstants.h"
#include "hook/hook.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, onDisconnect, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, const std::string &message)
{
	for(SMPlayer *player : ServerManager::getLevel()->getPlayers())
	{
		if(player->getHandle()->guid == guid)
		{
			real->level->getLevelStorage()->save(*player->getHandle());

			ServerPlayer *serverPlayer = (ServerPlayer *)player->getHandle();
			serverPlayer->disconnect();
			serverPlayer->remove();
			ServerManager::getLevel()->removePlayer(player);

			PlayerQuitEvent quitEvent(player, "§e%multiplayer.player.left", {player->getName()});
			ServerManager::getPluginManager()->callEvent(quitEvent);

			TextPacket pk;
			pk.type = TextPacket::TYPE_TRANSLATION;
			pk.message = quitEvent.getQuitMessage();
			pk.params = quitEvent.getQuitParams();
			real->sender->send(pk);

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

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, allowIncomingPacketId, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, int packetId)
{
	allowIncomingPacketId_real(real, guid, packetId);
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

	if(!valid || !iusername.compare(SMUtil::toLower(ServerManager::getLocalPlayer()->getName())) ||
			!iusername.compare("rcon") ||
			!iusername.compare("console") ||
			!iusername.compare("server"))
	{
		real->disconnectClient(guid, "disconnectionScreen.invalidName");
		return;
	}

	if(packet->skin.length() != 64 * 32 * 4 && packet->skin.length() != 64 * 64 * 4)
	{
		real->disconnectClient(guid, "disconnectionScreen.invalidSkin");
		return;
	}

	if(ServerManager::getBanList(BanList::NAME)->isBanned(iusername))
	{
		BanEntry *entry = ServerManager::getBanList(BanList::NAME)->getBanEntry(iusername);
		real->disconnectClient(guid, "You are banned from this server! Reason: " + entry->getReason());
		return;
	}

	if(ServerManager::hasWhitelist() && !ServerManager::isWhitelisted(iusername))
	{
		real->disconnectClient(guid, "You are not white-listed on this server!");
		return;
	}

	const char *ipAddress = real->raknet->getPeer()->GetSystemAddressFromGuid(guid).ToString(false);
	if (ServerManager::getBanList(BanList::IP)->isBanned(ipAddress))
	{
		BanEntry *entry = ServerManager::getBanList(BanList::IP)->getBanEntry(ipAddress);
		real->disconnectClient(guid, "Your IP address is banned from this server! Reason: " + entry->getReason());
		return;
	}
	sendLoginMessageLocal(real, guid, packet);
}

void CustomServerNetworkHandler::sendLoginMessageLocal(ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, LoginPacket *packet)
{
	PlayStatusPacket pk;
	pk.status = PlayStatusPacket::LOGIN_SUCCESS;
	real->sender->send(guid, pk);

	std::string iusername = SMUtil::toLower(packet->username);

	for(SMPlayer *p : ServerManager::getLevel()->getPlayers())
	{
		if(!SMUtil::toLower(p->getName()).compare(iusername))
			real->disconnectClient(guid, "You logged in from another location");
	}

	std::unique_ptr<ServerPlayer> playerPtr = real->createNewPlayer(guid, packet);
	ServerPlayer *player = playerPtr.get();

	Dimension *dimension = player->getDimension();
	if(!dimension)
		dimension = real->level->createDimension(DIMENSION_NORMAL);

	player->prepareRegion(*dimension->getChunkSource());

	real->_sendLevelData(player, guid);
	real->level->addPlayer(move(playerPtr));
	real->_sendAdditionalLevelData(player, guid);

	SMPlayer *smPlayer = new SMPlayer(player, real->raknet->getPeer()->GetSystemAddressFromGuid(guid).ToString(false));
	ServerManager::getLevel()->addPlayer(smPlayer);

	PlayerJoinEvent joinEvent(smPlayer, "");
	ServerManager::getPluginManager()->callEvent(joinEvent);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleText, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, TextPacket *packet)
{
	SMPlayer *player = _getPlayer(guid);
	if(!player->isDead())
		return;

	if(packet->type == TextPacket::TYPE_CHAT)
	{
		std::string username = player->getDisplayName();

		for(std::string message : SMUtil::split(packet->message, '\n'))
		{
			if(!SMUtil::trim(message).empty() && message.length() < 255)
			{
				if(message[0] == '#')
					ServerManager::dispatchCommand(player, message.erase(0, 1));
				else
					real->_displayGameMessage(username.c_str(), message.c_str());
			}
		}
	}
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMoveEntity, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MoveEntityPacket *packet)
{
	handleMoveEntity_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleMovePlayer, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, MovePlayerPacket *packet)
{
	handleMovePlayer_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleRemoveBlock, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, RemoveBlockPacket *packet)
{
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
	handleUseItem_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handlePlayerAction, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, PlayerActionPacket *packet)
{
	handlePlayerAction_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleDropItem, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, DropItemPacket *packet)
{
	Player *player = real->_getPlayer(guid);
	if(!player || !player->isAlive() || !ItemInstance::isItem(&packet->item))
		return;

	packet->item = *player->getSelectedItem();
	handleDropItem_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerClose, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerClosePacket *packet)
{
	handleContainerClose_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerSetSlot, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerSetSlotPacket *packet)
{
	handleContainerSetSlot_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleContainerSetContent, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, ContainerSetContentPacket *packet)
{
	handleContainerSetContent_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleCraftingEvent, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, CraftingEventPacket *packet)
{
	handleCraftingEvent_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleAnimate, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, AnimatePacket *packet)
{
	handleAnimate_real(real, guid, packet);
}

FUNCTION_HOOK_CPP(void, CustomServerNetworkHandler, handleBlockEntityData, ServerNetworkHandler *real, const RakNet::RakNetGUID &guid, BlockEntityDataPacket *packet)
{
	handleBlockEntityData_real(real, guid, packet);
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

SMPlayer *CustomServerNetworkHandler::_getPlayer(const RakNet::RakNetGUID &guid)
{
	for(SMPlayer *player : ServerManager::getLevel()->getPlayers())
	{
		if(player->getHandle()->guid == guid)
			return player;
	}
	return NULL;
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
