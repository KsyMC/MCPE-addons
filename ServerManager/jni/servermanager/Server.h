#pragma once

#include <string>
#include <vector>
#include <map>

#include "servermanager/BanList.h"
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
class SMEntity;
class SMLocalPlayer;
class Plugin;
class PluginCommand;
class Player;
class Entity;

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

	std::string newVersion;
	int newVersionCode;
	std::vector<std::string> newChangelog;

	std::map<Entity *, SMEntity *> entityList;
	std::vector<SMPlayer *> players;

public:
	Server();
	~Server();

	void init(Minecraft *server, const std::string &path);
	void load(const std::string &path);
	bool updateCheck();

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
	const std::vector<SMPlayer *> &getOnlinePlayers() const;
	SMPlayer *getPlayer(const std::string &name) const;
	std::vector<SMPlayer *> matchPlayer(const std::string &partialName) const;
	SMPlayer *getPlayerExact(const std::string &name) const;
	SMLocalPlayer *getLocalPlayer() const;

	void removePlayer(Player *player);
	SMPlayer *getPlayer(Player *player) const;

	void removeEntity(Entity *entity);
	SMEntity *getEntity(Entity *entity);

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

	BanList *getBanList(BanList::Type type) const;
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
