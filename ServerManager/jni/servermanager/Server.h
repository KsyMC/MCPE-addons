#pragma once

#include <string>
#include <vector>

#include "servermanager/plugin/PluginLoadOrder.h"
#include "minecraftpe/gamemode/GameType.h"

class SMLevel;
class SMOptions;
class BanList;
class SMList;
class SMPlayer;
class CommandMap;
class Level;
class PluginManager;
class Minecraft;
class LocalPlayer;
class SMLocalPlayer;
class Plugin;
class PluginCommand;

class Server
{
private:
	bool started;

	std::string serverDir;
	std::string pluginDir;

	SMLevel *level;
	Minecraft *server;
	SMOptions *options;

	BanList *banByName;
	BanList *banByIP;
	SMList *operators;
	SMList *whitelist;

	CommandMap *commandMap;
	PluginManager *pluginManager;

	SMLocalPlayer *localPlayer;

public:
	Server();
	~Server();

	void init(Minecraft *server, const std::string &path);
	void load(const std::string &path);

	void start(LocalPlayer *localPlayer, Level *level);
	void stop();

	SMOptions *getOptions() const;
	void saveOptions();

	void registerPlugin(Plugin *plugin);
	void loadPlugins();
	void enablePlugins(PluginLoadOrder type);
	void disablePlugins();

private:
	void setVanillaCommands();

	void loadPlugin(Plugin *plugin);

public:
	SMLocalPlayer *getLocalPlayer() const;

	void kickPlayer(SMPlayer *player, const std::string &reason);

	void broadcastMessage(const std::string &message);
	void broadcastTranslation(const std::string &message, const std::vector<std::string> &params);
	void broadcastTip(const std::string &message);
	void broadcastPopup(const std::string &message, const std::string &subtitle = "");

	int getMaxPlayers() const;
	int getPort() const;
	int getViewDistance() const;
	std::string getServerName() const;
	bool hasWhitelist() const;
	bool getPvP() const;

	void setWhitelist(bool value);
	void setPvP(bool value);

	bool dispatchCommand(SMPlayer *player, const std::string &commandLine);

	PluginCommand *getPluginCommand(const std::string &name);

	SMLevel *getLevel() const;

	BanList *getBanList(int type) const;
	SMList *getWhitelistList() const;
	SMList *getOPList() const;

	void banIP(const std::string &address);
	void unbanIP(const std::string &address);

	void addWhitelist(const std::string &name);
	void removeWhitelist(const std::string &name);
	void reloadWhitelist();

	void addOp(const std::string &name);
	void removeOp(const std::string &name);

	bool isWhitelisted(const std::string &name) const;
	bool isOp(const std::string &name) const;

	CommandMap *getCommandMap() const;
	PluginManager *getPluginManager() const;

	static std::string getGamemodeString(GameType type);
	static GameType getGamemodeFromString(const std::string &value);

	Minecraft *getServer() const;
};
