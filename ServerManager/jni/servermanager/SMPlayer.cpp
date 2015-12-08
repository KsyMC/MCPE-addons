#include "SMPlayer.h"
#include "ServerManager.h"
#include "level/SMLevel.h"
#include "network/PacketId.h"
#include "utils/SMList.h"
#include "utils/SMOptions.h"
#include "utils/SMUtil.h"

#include "minecraftpe/ServerPlayer.h"
#include "minecraftpe/PacketSender.h"
#include "minecraftpe/LoginPacket.h"
#include "minecraftpe/TextPacket.h"
#include "minecraftpe/DisconnectPacket.h"
#include "minecraftpe/PlayStatusPacket.h"
#include "minecraftpe/MovePlayerPacket.h"
#include "minecraftpe/Level.h"
#include "minecraftpe/LevelStorage.h"
#include "minecraftpe/SharedConstants.h"
#include "minecraftpe/I18n.h"

SMPlayer::SMPlayer(ServerManager *server, PacketSender *packetSender, RakNet::RakNetGUID const &guid, std::string const &ip, unsigned short port)
{
	realPlayer = NULL;

	spawned = false;
	loggedIn = false;

	setLevel(server->getLevel());

	this->server = server;

	realPlayer = NULL;
	this->guid = guid;

	this->packetSender = packetSender;

	this->ip = ip;
	this->port = port;

	connected = true;

	messageCounter = 2;
}

SMPlayer::~SMPlayer()
{

}

TextContainer SMPlayer::getLeaveMessage() const
{
	return TextContainer("§e%multiplayer.player.left", {displayName});
}

bool SMPlayer::isConnected() const
{
	return connected;
}

bool SMPlayer::isOnline()
{
	return connected && loggedIn;
}

std::string SMPlayer::getName() const
{
	return username;
}

std::string SMPlayer::getDisplayName() const
{
	return displayName;
}

bool SMPlayer::isBanned() const
{
	return server->isBanned(username);
}

bool SMPlayer::isWhitelisted() const
{
	return server->isWhitelisted(username);
}

bool SMPlayer::isOp() const
{
	return server->isOp(username);
}

void SMPlayer::setBanned(bool value)
{
	if(value)
	{
		server->addBanned(username);
		kick("You have been banned");
	}
	else
		server->removeBanned(username);
}

void SMPlayer::setWhitelisted(bool value)
{
	if(value)
		server->addWhitelist(username);
	else
		server->removeWhitelist(username);
}

void SMPlayer::setOp(bool value)
{
	if(value == isOp())
		return;

	if(value)
		server->addOp(username);
	else
		server->removeOp(username);
}

std::string SMPlayer::getAddress() const
{
	return ip;
}

unsigned short SMPlayer::getPort() const
{
	return port;
}

bool SMPlayer::dataPacket(Packet const &packet)
{
	if(!connected)
		return false;

	packetSender->send(guid, packet);

	return true;
}

int SMPlayer::getGamemode() const
{
	return realPlayer->gameType;
}

void SMPlayer::setGamemode(int mode)
{
	realPlayer->setPlayerGameType((GameType)mode);
}

bool SMPlayer::isSurvival() const
{
	return realPlayer->IsSurvival();
}

bool SMPlayer::isCreative() const
{
	return realPlayer->IsCreative();
}

SMPlayer *SMPlayer::getPlayer()
{
	return this;
}

bool SMPlayer::isLocalPlayer() const
{
	return false;
}

void SMPlayer::setLevel(SMLevel *level)
{
	this->level = level;
}

SMLevel *SMPlayer::getLevel() const
{
	return level;
}

Inventory *SMPlayer::getInventory() const
{
	return realPlayer->inventory;
}

BlockSource *SMPlayer::getBlockSource() const
{
	return realPlayer->getRegion();
}

void SMPlayer::save()
{
	if(realPlayer)
		server->getLevel()->get()->getLevelStorage()->save(*realPlayer);
}

void SMPlayer::teleport(SMPlayer *target)
{
	teleport(target->get()->getPos(), target->get()->getRotation());
}

void SMPlayer::teleport(Vec3 const &pos, Vec2 const &rot)
{
	realPlayer->moveTo(pos, rot);

	MovePlayerPacket pk;
	pk.id = realPlayer->getUniqueID();
	pk.pos = pos;
	pk.rot = rot;
	pk.bodyYaw = rot.y;
	pk.mode = MovePlayerPacket::MODE_RESET;
	pk.onGround = true;
	dataPacket(pk);
}

void SMPlayer::sendMessage(TextContainer const &message)
{
	if(message.isNeedTranslation())
	{
		sendTranslation(message.getText(), message.getParameters());
		return;
	}

	for(std::string m : SMUtil::split(I18n::get(message.getText()), '\n'))
	{
		if(m.empty())
			continue;

		TextPacket pk;
		pk.type = TextPacket::TYPE_RAW;
		pk.message = m;
		dataPacket(pk);
	}
}

void SMPlayer::sendTranslation(std::string const &message, std::vector<std::string> const &parameters)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TRANSLATION;
	pk.message = message;
	pk.parameters = parameters;
	dataPacket(pk);
}

void SMPlayer::sendPopup(std::string const &message, std::string const &subtitle)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_POPUP;
	pk.source = message;
	pk.message = subtitle;
	dataPacket(pk);
}

void SMPlayer::sendTip(std::string const &message)
{
	TextPacket pk;
	pk.type = TextPacket::TYPE_TIP;
	pk.message = message;
	dataPacket(pk);
}

void SMPlayer::kick(std::string const &reason, bool isAdmin)
{
	std::string message;

	if(isAdmin)
		message = "Kicked by admin." + (!reason.empty() ? " Reason: " + reason : "");
	else
	{
		if(reason.empty())
			message = "disconnectionScreen.noReason";
		else
			message = reason;
	}
	close(getLeaveMessage(), message);
}

void SMPlayer::close(TextContainer const &message, std::string const &reason, bool notify)
{
	if(connected)
	{
		if(notify && !reason.empty())
		{
			DisconnectPacket pk;
			pk.message = reason;
			dataPacket(pk);
		}
		connected = false;

		save();

		loggedIn = false;

		if(!username.empty() && spawned && !message.getText().empty())
			server->broadcastMessage(message);

		spawned = false;

		if(realPlayer)
		{
			ServerPlayer *serverPlayer = (ServerPlayer *)realPlayer;
			serverPlayer->disconnect();
			serverPlayer->remove();
		}
	}
	server->removePlayer(this);
}

void SMPlayer::handleDataPacket(Packet *packet)
{
	if(!connected)
		return;

	switch((packet->getId() - 1) + 0x8f)
	{
		case PacketId::LOGIN_PACKET:
		{
			if(loggedIn)
				break;

			LoginPacket *loginPacket = (LoginPacket *)packet;

			username = loginPacket->username;
			displayName = username;
			iusername = SMUtil::toLower(username);

			if(loginPacket->protocol1 != SharedConstants::NetworkProtocolVersion)
			{
				PlayStatusPacket statusPacket;
				if(loginPacket->protocol1 < SharedConstants::NetworkProtocolVersion)
				{
					close(getLeaveMessage(), "disconnectionScreen.outdatedClient");
					statusPacket.status = PlayStatusPacket::LOGIN_FAILED_CLIENT;
				}
				else
				{
					close(getLeaveMessage(), "disconnectionScreen.outdatedServer");
					statusPacket.status = PlayStatusPacket::LOGIN_FAILED_SERVER;
				}
				dataPacket(statusPacket);

				break;
			}

			bool valid = true;

			int len = username.length();
			if(len > 16 || len < 3)
				valid = false;

			if(!valid || !username.compare("rcon") || !username.compare("console") ||
					!SMUtil::toLower(username).compare(SMUtil::toLower(server->getHost()->getName())))
			{
				close(getLeaveMessage(), "disconnectionScreen.invalidName");
				break;
			}

			if(loginPacket->skin.length() != 64 * 32 * 4 && loginPacket->skin.length() != 64 * 64 * 4)
			{
				close(getLeaveMessage(), "disconnectionScreen.invalidSkin");
				break;
			}

			SMOptions *options = server->getOptions();
			if(options->isWhitelist() && !server->getWhitelistList()->isExist(SMUtil::toLower(username)))
			{
				close(getLeaveMessage(), "Server is white-listed");
				break;
			}

			if(server->getBanList()->isExist(SMUtil::toLower(username)) || server->getBanIpList()->isExist(ip))
			{
				close(getLeaveMessage(), "You are banned");
				break;
			}

			for(SMPlayer *p : server->getOnlinePlayers())
			{
				if(p != this && !SMUtil::toLower(p->getName()).compare(SMUtil::toLower(username)))
				{
					p->kick("logged in from another location");
					break;
				}
			}
			if(options->isAllowOnlyWifiIp() && !server->isWifiIp(ip))
			{
				close(getLeaveMessage(), "와이파이만 접속 가능");
				break;
			}

			if(options->isShowIp())
			{
				for(SMPlayer *player : server->getOnlinePlayers())
				{
					if(player->isLocalPlayer() || player->isOp())
						player->sendMessage(TextContainer("§a" + username + "'s IP:" + ip));
				}
			}

			loggedIn = true;

			PlayStatusPacket statusPacket;
			statusPacket.status = PlayStatusPacket::LOGIN_SUCCESS;
			dataPacket(statusPacket);

			realPlayer = server->createNewPlayer(guid, loginPacket);

			spawned = true;

			break;
		}
		case PacketId::TEXT_PACKET:
		{
			if(!spawned || !realPlayer->isAlive())
				break;

			TextPacket *textPacket = (TextPacket *)packet;
			if(textPacket->type != TextPacket::TYPE_CHAT)
				break;

			for(std::string message : SMUtil::split(textPacket->message, '\n'))
			{
				if(SMUtil::trim(message).empty() || message.length() >= 255 || messageCounter-- <= 0)
					continue;

				if(message[0] == '/')
					server->dispatchCommand(this, message.erase(0, 1));
				else
					server->broadcastMessage(TextContainer(I18n::get("chat.type.text", {displayName, message})));
			}
			break;
		}
	}
}

void SMPlayer::onUpdate()
{
	if(!loggedIn)
		return;

	messageCounter = 2;
}

ServerManager *SMPlayer::getServer() const
{
	return server;
}

Player *SMPlayer::get() const
{
	return realPlayer;
}
