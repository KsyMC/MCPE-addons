#include "servermanager/entity/SMPlayer.h"
#include "servermanager/Server.h"
#include "servermanager/BanList.h"
#include "servermanager/BanEntry.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/level/SMBlockSource.h"
#include "servermanager/event/player/PlayerGameModeChangeEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/resources/I18n.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/network/PacketSender.h"
#include "minecraftpe/network/protocol/TextPacket.h"
#include "minecraftpe/network/protocol/MovePlayerPacket.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/BlockSource.h"
#include "minecraftpe/level/LevelStorage.h"

SMPlayer::SMPlayer(Server *server, Player *entity)
	: SMMob(server, entity)
{
	joined = false;

	lastPosX = 0;
	lastPosY = 0;
	lastPosZ = 0;
	lastYaw = 0;
	lastPitch = 0;
	justTeleported = false;

	lastPacket = 0;
	lastBlock = 0;

	displayName = entity->username;
	listName = entity->username;
}

SMPlayer::~SMPlayer()
{
}

void SMPlayer::sendRawMessage(const std::string &message)
{
	if(!joined)
		return;

	for(std::string m : SMUtil::split(message, '\n'))
	{
		if(!m.empty())
		{
			TextPacket pk;
			pk.type = TextPacket::TYPE_RAW;
			pk.message = m;
			getPacketSender()->send(getHandle()->guid, pk);
		}
	}
}

void SMPlayer::sendMessage(const std::string &message)
{
	sendRawMessage(message);
}

void SMPlayer::sendMessage(const std::vector<std::string> messages)
{
	for(std::string message : messages)
		sendMessage(message);
}

void SMPlayer::sendTranslation(const std::string &message, const std::vector<std::string> &params)
{
	if(!joined)
		return;

	TextPacket pk;
	pk.type = TextPacket::TYPE_TRANSLATION;
	pk.message = message;
	pk.params = params;
	getPacketSender()->send(getHandle()->guid, pk);
}

void SMPlayer::sendPopup(const std::string &message, const std::string &subtitle)
{
	if(!joined)
		return;

	TextPacket pk;
	pk.type = TextPacket::TYPE_POPUP;
	pk.source = message;
	pk.message = subtitle;
	getPacketSender()->send(getHandle()->guid, pk);
}

void SMPlayer::sendTip(const std::string &message)
{
	if(!joined)
		return;

	TextPacket pk;
	pk.type = TextPacket::TYPE_TIP;
	pk.message = message;
	getPacketSender()->send(getHandle()->guid, pk);
}

bool SMPlayer::isLocalPlayer() const
{
	return false;
}

bool SMPlayer::isOp() const
{
	return server->isOp(getName());
}

void SMPlayer::setOp(bool value)
{
	if(value == isOp())
		return;

	if(value)
		server->addOp(getName());
	else
		server->removeOp(getName());
}

float SMPlayer::getEyeHeight() const
{
	return getEyeHeight(false);
}

float SMPlayer::getEyeHeight(bool ignoreSneaking) const
{
	if(ignoreSneaking)
		return 1.62f;
	else
	{
		if(isSneaking())
			return 1.54f;
		else
			return 1.62;
	}
}

void SMPlayer::setSneaking(bool sneak)
{
	getHandle()->setSneaking(sneak);
}

bool SMPlayer::isSneaking() const
{
	return getHandle()->isSneaking();
}

void SMPlayer::setSprinting(bool sprinting)
{
	getHandle()->setSprinting(sprinting);
}

bool SMPlayer::isSprinting() const
{
	return getHandle()->isSprinting();
}

PacketSender *SMPlayer::getPacketSender() const
{
	return getHandle()->packetSender;
}

const std::string &SMPlayer::getAddress() const
{
	return ipAddress;
}

void SMPlayer::setAddress(const char *ipAddress)
{
	this->ipAddress = ipAddress;
}

std::string SMPlayer::getDisplayName() const
{
	return displayName;
}

void SMPlayer::setDisplayName(const std::string &name)
{
	displayName = name;
}

bool SMPlayer::teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause)
{
	if(getHealth() <= 0 || isDead())
		return false;

	Location from = getLocation();
	Location to = location;

	PlayerTeleportEvent event(this, from, to, cause);
	server->getPluginManager()->callEvent(event);

	if(event.isCancelled())
		return false;

	if(getHandle()->isRiding())
		getHandle()->stopRiding(false);

	from = event.getFrom();
	to = event.getTo();

	DimensionId fromId = from.getRegion()->getHandle()->getDimensionId();
	DimensionId toId = to.getRegion()->getHandle()->getDimensionId();

	if(getHandle()->activeContainer)
		getHandle()->closeContainer();

	if(fromId == toId)
		getHandle()->moveTo(to.getPos(), to.getRotation());
	else
	{
		getHandle()->changeDimension(toId);
		getHandle()->moveTo(to.getPos(), to.getRotation());
	}

	if(!isLocalPlayer())
	{
		MovePlayerPacket pk;
		pk.uniqueID = getHandle()->getUniqueID();
		pk.pos = to.getPos();
		pk.rot = to.getRotation();
		pk.yaw = to.getRotation().y;
		pk.mode = MovePlayerPacket::RESET;
		pk.onGround = false;
		getPacketSender()->send(getHandle()->guid, pk);
	}

	lastPosX = to.getX();
	lastPosY = to.getY();
	lastPosZ = to.getZ();
	lastYaw = to.getYaw();
	lastPitch = to.getPitch();
	justTeleported = true;

	return true;
}

void SMPlayer::setGameType(GameType gametype)
{
	if(gametype != getGameType())
	{
		PlayerGameModeChangeEvent event(this, gametype);
		server->getPluginManager()->callEvent(event);

		if(event.isCancelled())
			return;

		getHandle()->setPlayerGameType(gametype);
		getHandle()->fallDistance = 0;
	}
}

GameType SMPlayer::getGameType() const
{
	return getHandle()->gameType;
}

Player *SMPlayer::getHandle() const
{
	return (Player *)entity;
}

void SMPlayer::setHandle(Player *player)
{
	entity = player;
}

std::string SMPlayer::getName() const
{
	return getHandle()->username;
}

Inventory *SMPlayer::getInventory() const
{
	return getHandle()->inventory;
}

ItemInstance *SMPlayer::getSelectedItem() const
{
	return getHandle()->getSelectedItem();
}
