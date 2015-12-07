#include <algorithm>

#include "ServerManager.h"
#include "SMLocalPlayer.h"
#include "SMOfflinePlayer.h"
#include "level/SMLevel.h"
#include "command/SimpleCommandMap.h"
#include "utils/SMOptions.h"
#include "utils/SMList.h"
#include "utils/SMUtil.h"

#include "minecraftpe/LocalPlayer.h"
#include "minecraftpe/Minecraft.h"
#include "minecraftpe/MinecraftClient.h"
#include "minecraftpe/ServerNetworkHandler.h"
#include "minecraftpe/ServerPlayer.h"
#include "minecraftpe/Dimension.h"

static const std::vector<const char *> vecDataIps =
{
	// SKT
	"211.234",
	"203.226",
	"223.62",
	"175.202",
	"122.32",
	"121.190",
	"122.202",
	"115.161",

	// KT
	"211.246",
	"110.70",
	"175.223",
	"39.7",
	"110.70",
	"175.223",
	"210.125",
	"175.252",

	// LGT
	"211.234",
	"61.43",
	"211.226",
	"117.111",
	"211.36",
	"114.200"
};

ServerManager::ServerManager()
{
	started = false;

	network = NULL;

	level = NULL;

	options = new SMOptions();
	banList = new SMList();
	banIpList = new SMList();
	whitelistList = new SMList();
	operatorsList = new SMList();

	host = NULL;

	commandMap = new SimpleCommandMap;
}

ServerManager::~ServerManager()
{
	delete options;
	delete banList;
	delete banIpList;
	delete whitelistList;
	delete operatorsList;

	delete commandMap;
}

int ServerManager::getMaxPlayers() const
{
	return options->getServerPlayers();
}

int ServerManager::broadcastMessage(TextContainer const &message)
{
	for(SMPlayer *player : players)
		player->sendMessage(message);
}

int ServerManager::broadcastTip(std::string const &tip)
{
	for(SMPlayer *player : players)
		player->sendTip(tip);
}

int ServerManager::broadcastPopup(std::string const &popup)
{
	for(SMPlayer *player : players)
		player->sendPopup(popup);
}

void ServerManager::broadcastPacket(std::vector<SMPlayer *> const &players, Packet const &packet)
{
	for(SMPlayer *player : players)
		player->dataPacket(packet);
}

bool ServerManager::dispatchCommand(SMPlayer *sender, std::string const &commandLine)
{
	if(!sender->isLocalPlayer() && !sender->isOp()) // 나중에 퍼미션 추가
	{
		sender->sendMessage(TextContainer("§c%commands.generic.permission", true));
		return false;
	}

	if(commandMap->dispatch(sender, commandLine))
		return true;

	sender->sendMessage(TextContainer("§c%commands.generic.notFound", true));

	return false;
}

ServerPlayer *ServerManager::createNewPlayer(const RakNet::RakNetGUID &guid, LoginPacket *packet)
{
	std::unique_ptr<ServerPlayer> playerPtr = network->createNewPlayer(guid, packet);
	ServerPlayer *player = playerPtr.get();

	Level *realLevel = level->get();

	Dimension *dimension = player->getDimension();
	if(!dimension)
		dimension = realLevel->createDimension(DIMENSION_NORMAL);

	player->prepareRegion(*dimension->getChunkSource());
	network->_sendLevelData(player, guid);
	realLevel->addPlayer(std::move(playerPtr));
	network->_sendAdditionalLevelData(player, guid);

	return player;
}

SMLevel *ServerManager::getLevel() const
{
	return level;
}

void ServerManager::addPlayer(SMPlayer *player)
{
	players.push_back(player);
}

SMPlayer *ServerManager::getPlayer(std::string const &name) const
{
	SMPlayer *found = NULL;
	std::string newName = SMUtil::toLower(name);
	int delta = 2147483647;

	for(SMPlayer *player : players)
	{
		std::string n = SMUtil::toLower(player->getName());
		if(n.find(newName) != std::string::npos)
		{
			int curDelta = n.length() - newName.length();
			if(curDelta < delta)
			{
				found = player;
				delta = curDelta;
			}

			if(curDelta == 0)
				break;
		}
	}
	return found;
}

SMPlayer *ServerManager::getPlayerExact(std::string const &name) const
{
	std::string newName = SMUtil::toLower(name);
	for(SMPlayer *player : players)
	{
		if(!SMUtil::toLower(player->getName()).compare(newName))
			return player;
	}
	return NULL;
}

ISMPlayer *ServerManager::getOfflinePlayer(std::string const &name)
{
	std::string newName = SMUtil::toLower(name);

	SMPlayer *player = getPlayerExact(newName);
	if(player)
		return player;

	return new SMOfflinePlayer(this, newName);
}

std::vector<SMPlayer *> ServerManager::getOnlinePlayers() const
{
	return players;
}

void ServerManager::removePlayer(SMPlayer *player)
{
	players.erase(std::find(players.begin(), players.end(), player));
	delete player;
}

SMPlayer *ServerManager::getHost() const
{
	return host;
}

SMOptions *ServerManager::getOptions() const
{
	return options;
}

void ServerManager::load(std::string const &filePath)
{
	options->load(filePath + "servermanager.txt");
	banList->load(filePath + "banned-players.txt");
	banIpList->load(filePath + "banned-ips.txt");
	whitelistList->load(filePath + "white-list.txt");
	operatorsList->load(filePath + "ops.txt");
}

void ServerManager::startServer(LocalPlayer *hostPlayer)
{
	if(started)
		return;

	Minecraft *server = hostPlayer->mc->getServer();

	level = new SMLevel(this, server->getLevel());

	if(isOnlineClient())
		return;

	network = (ServerNetworkHandler *)server->getNetEventCallback();

	SMLocalPlayer *player = new SMLocalPlayer(this, hostPlayer, hostPlayer->guid);
	addPlayer(player);

	host = player;

	started = true;
}

bool ServerManager::isStarted() const
{
	return started;
}

void ServerManager::leaveServer()
{
	if(!started)
		return;

	started = false;

	for(SMPlayer *player : players)
		delete player;

	players.clear();
}

CommandMap *ServerManager::getCommandMap() const
{
	return commandMap;
}

std::string ServerManager::getGamemodeString(int mode)
{
	switch(mode)
	{
	case GameType::SURVIVAL:
		return "%gameMode.survival";
	case GameType::CREATIVE:
		return "%gameMode.creative";
	case GameType::ADVENTURE:
		return "%gameMode.adventure";
	case GameType::SPECTATOR:
		return "%gameMode.spectator";
	}
	return "UNKNOWN";
}

int ServerManager::getGamemodeFromString(std::string const &str)
{
	std::string newStr = SMUtil::toLower(SMUtil::trim(str.c_str()));

	if(!newStr.compare("0") || !newStr.compare("survival") || !newStr.compare("s"))
		return GameType::SURVIVAL;
	else if(!newStr.compare("1") || !newStr.compare("creative") || !newStr.compare("c"))
		return GameType::CREATIVE;
	else if(!newStr.compare("2") || !newStr.compare("adventure") || !newStr.compare("a"))
		return GameType::ADVENTURE;
	else if(!newStr.compare("3") || !newStr.compare("spectator") || !newStr.compare("view") || !newStr.compare("v"))
		return GameType::SPECTATOR;
	return -1;
}

bool ServerManager::isOnlineClient() const
{
	return level->get()->isClientSide();
}

bool ServerManager::hasWhitelist() const
{
	return options->isWhitelist();
}

void ServerManager::addOp(std::string const &name)
{
	operatorsList->add(SMUtil::toLower(name));
	operatorsList->save();
}

void ServerManager::removeOp(std::string const &name)
{
	operatorsList->remove(SMUtil::toLower(name));
	operatorsList->save();
}

bool ServerManager::isOp(std::string const &name) const
{
	return operatorsList->isExist(SMUtil::toLower(name));
}

void ServerManager::addWhitelist(std::string const &name)
{
	whitelistList->add(SMUtil::toLower(name));
	whitelistList->save();
}

void ServerManager::removeWhitelist(std::string const &name)
{
	whitelistList->remove(SMUtil::toLower(name));
	whitelistList->save();
}

bool ServerManager::isWhitelisted(std::string const &name) const
{
	return !options->isWhitelist() || operatorsList->isExist(SMUtil::toLower(name)) || whitelistList->isExist(SMUtil::toLower(name));
}

void ServerManager::reloadWhitelist()
{
	whitelistList->reload();
}

void ServerManager::addBanned(std::string const &name)
{
	banList->add(SMUtil::toLower(name));
	banList->save();
}

void ServerManager::removeBanned(std::string const &name)
{
	banList->remove(SMUtil::toLower(name));
	banList->save();
}

bool ServerManager::isBanned(std::string const &name) const
{
	return banList->isExist(SMUtil::toLower(name));
}

SMList *ServerManager::getBanList() const
{
	return banList;
}

SMList *ServerManager::getBanIpList() const
{
	return banIpList;
}

SMList *ServerManager::getWhitelistList() const
{
	return whitelistList;
}

SMList *ServerManager::getOperatorsList() const
{
	return operatorsList;
}

bool ServerManager::isWifiIp(std::string const &ip) const
{
	std::vector<std::string> ipPart = SMUtil::split(ip, '.');
	return std::find(vecDataIps.begin(), vecDataIps.end(), ipPart[0] + "." + ipPart[1]) == vecDataIps.end();
}
