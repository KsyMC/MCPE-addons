#pragma once

#include "servermanager/command/CommandExecutor.h"

class Server;
class PluginDescriptionFile;

class Plugin : public CommandExecutor
{
public:
	virtual std::string getDataFolder() = 0;

	virtual PluginDescriptionFile *getDescription() const = 0;

	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
	virtual void onLoad() = 0;

	virtual std::string getName() const = 0;

	virtual std::string getPluginDescription() const = 0;

	virtual void saveConfig() = 0;
	virtual void saveDefaultConfig() = 0;
	virtual void saveResource(const std::string &resourcePath, bool replace) = 0;

	virtual void reloadConfig() = 0;

	virtual Server *getServer() const = 0;

	virtual bool isEnabled() const = 0;
};
