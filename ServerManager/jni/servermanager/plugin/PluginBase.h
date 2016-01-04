#pragma once

#include "servermanager/plugin/Plugin.h"

class PluginCommand;

class PluginBase : public Plugin
{
private:
	bool enabled;
	Server *server;
	PluginDescriptionFile *description;
	std::string dataFolder;
	std::string confingFile;

public:
	PluginBase();
	~PluginBase();

	std::string getDataFolder();

	void onEnable();
	void onDisable();
	void onLoad();

	std::string getName() const;

	PluginDescriptionFile *getDescription() const;

	void saveConfig();
	void saveDefaultConfig();
	void saveResource(const std::string &resourcePath, bool replace);

	void reloadConfig();

	Server *getServer() const;

	bool isEnabled() const;
	void setEnabled(bool enabled);

	void init(Server *server, PluginDescriptionFile *description, const std::string &dataFolder);

	bool onCommand(SMPlayer *sender, Command *command, std::string &label, std::vector<std::string> &args);

	PluginCommand *getCommand(std::string &name);
};
