#pragma once

#include "servermanager/Server.h"

class ServerManager
{
private:
	static Server *server;

public:
	static Server *getServer();
	static void setServer(Server *server);
	static void deleteServer();

	static int getMaxPlayers();
	static int getPort();
	static int getViewDistance();
	static std::string getServerName();
	static void broadcastMessage(const std::string &message);
	static void broadcastTranslation(const std::string &message, const std::vector<std::string> &params);
	static void broadcastTip(const std::string &message);
	static void broadcastPopup(const std::string &message, const std::string &subtitle = "");
	static bool hasWhitelist();
	static bool isWhitelisted(const std::string &name);
	static bool dispatchCommand(SMPlayer *sender, const std::string &commandLine);
	static PluginCommand *getPluginCommand(const std::string &name);
	static void banIP(const std::string &address);
	static void unbanIP(const std::string &address);
	static BanList *getBanList(BanList::Type type);
	static void setWhitelist(bool value);
	static SMList *getWhitelist();
	static void reloadWhitelist();
	static SMLevel *getLevel();
	static PluginManager *getPluginManager();
	static const std::vector<SMPlayer *> &getOnlinePlayers();
	static SMPlayer *getPlayer(const std::string &name);
	static std::vector<SMPlayer *> matchPlayer(const std::string &partialName);
	static SMPlayer *getPlayerExact(const std::string &name);
	static SMLocalPlayer *getLocalPlayer();
	static SMEntity *getEntity(Entity *entity);
	static void kickPlayer(SMPlayer *player, const std::string &reason);
	static void registerPlugin(Plugin *plugin);
};
