#pragma once

#include <string>
#include <vector>
#include "event/TextContainer.h"
#include "minecraftpe/GameType.h"

namespace RakNet
{
	class RakNetGUID;
};

class ServerNetworkHandler;
class Level;
class SMOptions;
class SMList;
class ISMPlayer;
class SMPlayer;
class CommandMap;
class MinecraftClient;
class LocalPlayer;
class ServerPlayer;
class LoginPacket;

class ServerManager
{
private:
	bool started;

	ServerNetworkHandler *network;

	Level *level;

	SMOptions *options;
	SMList *banList;
	SMList *banIpList;
	SMList *whitelistList;
	SMList *operatorsList;

	SMPlayer *host;
	std::vector<SMPlayer *> players;

	CommandMap *commandMap;

public:
	ServerManager();
	~ServerManager();

	int getMaxPlayers() const;

	int broadcastMessage(TextContainer const &message);
	int broadcastTip(std::string const &tip);
	int broadcastPopup(std::string const &popup);

	bool dispatchCommand(SMPlayer *sender, std::string const &commandLine);

	ServerPlayer *createNewPlayer(const RakNet::RakNetGUID &guid, LoginPacket *packet);

	Level *getLevel() const;

	void addPlayer(SMPlayer *player);
	SMPlayer *getPlayer(std::string const &name) const;
	SMPlayer *getPlayerExact(std::string const &name) const;
	ISMPlayer *getOfflinePlayer(std::string const &name);
	std::vector<SMPlayer *> getOnlinePlayers() const;
	void removePlayer(SMPlayer *player);
	SMPlayer *getHost() const;

	SMOptions *getOptions() const;

	void load(std::string const &filePath);

	void startServer(LocalPlayer *hostPlayer);
	bool isStarted() const;
	void leaveServer();

	CommandMap *getCommandMap() const;

	static std::string getGamemodeString(int mode);
	static int getGamemodeFromString(std::string const &str);

	bool isOnlineClient() const;

	bool hasWhitelist() const;

	void addOp(std::string const &name);
	void removeOp(std::string const &name);
	bool isOp(std::string const &name) const;

	void addWhitelist(std::string const &name);
	void removeWhitelist(std::string const &name);
	bool isWhitelisted(std::string const &name) const;
	void reloadWhitelist();

	void addBanned(std::string const &name);
	void removeBanned(std::string const &name);
	bool isBanned(std::string const &name) const;

	SMList *getBanList() const;
	SMList *getBanIpList() const;
	SMList *getWhitelistList() const;
	SMList *getOperatorsList() const;

	bool isWifiIp(std::string const &ip) const;
};
