#pragma once

#include <string>
#include <vector>
#include <map>
#include <json/json.h>

#include "servermanager/plugin/PluginLoadOrder.h"

class PluginDescriptionFile
{
public:
	struct CommandDescValue
	{
		bool isArray;
		std::string strValue;
		std::vector<std::string> arrayValue;
	};

private:
	bool loaded;

	std::string name;
	std::vector<std::string> depend;
	std::vector<std::string> softDepend;
	std::vector<std::string> loadBefore;
	std::string version;
	std::map<std::string, std::map<std::string, CommandDescValue>> commands;
	std::string description;
	std::vector<std::string> authors;
	std::string website;
	std::string prefix;
	PluginLoadOrder order;

public:
	PluginDescriptionFile(const std::string &path);
	PluginDescriptionFile(const std::string &pluginName, const std::string &pluginVersion);

private:
	void loadJson(const std::string &path);
	std::vector<std::string> makePluginNameList(Json::Value root, const std::string &key);

public:
	bool isLoaded() const;

	const std::string &getName() const;
	const std::string &getVersion() const;
	const std::string &getDescription() const;
	PluginLoadOrder getLoad() const;
	const std::vector<std::string> &getAuthors() const;
	const std::string &getWebsite() const;
	const std::vector<std::string> &getDepend() const;
	const std::vector<std::string> &getSoftDepend() const;
	const std::vector<std::string> &getLoadBefore() const;
	const std::string &getPrefix() const;
	const std::map<std::string, std::map<std::string, CommandDescValue>> &getCommands() const;
	std::string getFullName() const;
};
