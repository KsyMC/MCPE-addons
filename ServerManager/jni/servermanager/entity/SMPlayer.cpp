#include "servermanager/entity/SMPlayer.h"
#include "servermanager/Server.h"
#include "servermanager/client/resources/BanList.h"
#include "servermanager/client/resources/BanEntry.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/level/SMBlockSource.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/resources/I18n.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/network/PacketSender.h"
#include "minecraftpe/network/protocol/TextPacket.h"
#include "minecraftpe/network/protocol/MovePlayerPacket.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/LevelStorage.h"

SMPlayer::SMPlayer(Player *entity, const std::string &ipAddress)
	: SMMob(entity)
{
	region = new SMBlockSource(this);

	displayName = entity->username;
	listName = entity->username;

	this->ipAddress = ipAddress;
}

SMPlayer::~SMPlayer()
{
	delete region;
}

void SMPlayer::sendMessage(const std::string &message)
{
	for(std::string m : SMUtil::split(message, '\n'))
	{
		if(m.empty())
			continue;

		TextPacket pk;
		pk.type = TextPacket::TYPE_RAW;
		pk.message = m;
		getPacketSender()->send(getHandle()->guid, pk);
	}
}

void SMPlayer::sendTranslation(const std::string &message, const std::vector<std::string> &params)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TRANSLATION;
	pk.message = message;
	pk.params = params;
	getPacketSender()->send(getHandle()->guid, pk);
}

void SMPlayer::sendPopup(const std::string &message, const std::string &subtitle)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_POPUP;
	pk.source = message;
	pk.message = subtitle;
	getPacketSender()->send(getHandle()->guid, pk);
}

void SMPlayer::sendTip(const std::string &message)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TIP;
	pk.message = message;
	getPacketSender()->send(getHandle()->guid, pk);
}

bool SMPlayer::isLocalPlayer() const
{
	return false;
}

PacketSender *SMPlayer::getPacketSender() const
{
	return getHandle()->packetSender;
}

const std::string &SMPlayer::getAddress() const
{
	return ipAddress;
}

std::string SMPlayer::getDisplayName() const
{
	return displayName;
}

void SMPlayer::setDisplayName(const std::string &name)
{
	displayName = name;
}

void SMPlayer::teleport(SMPlayer *target)
{
	teleport(target->getHandle()->getPos(), target->getHandle()->getRotation());
}

void SMPlayer::teleport(const Vec3 &pos, const Vec2 &rot)
{
	getHandle()->moveTo(pos, rot);

	MovePlayerPacket pk;
	pk.id = getHandle()->getUniqueID();
	pk.pos = pos;
	pk.rot = rot;
	pk.bodyYaw = rot.y;
	pk.mode = MovePlayerPacket::MODE_RESET;
	pk.onGround = false;
	getPacketSender()->send(getHandle()->guid, pk);
}

void SMPlayer::setGameType(GameType gametype)
{
	getHandle()->setPlayerGameType(gametype);
}

int SMPlayer::getGameType() const
{
	return getHandle()->gameType;
}

Player *SMPlayer::getHandle() const
{
	return (Player *)entity;
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

SMBlockSource *SMPlayer::getRegion() const
{
	return region;
}
