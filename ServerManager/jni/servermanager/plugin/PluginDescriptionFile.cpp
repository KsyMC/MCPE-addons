#include <fstream>

#include "servermanager/plugin/PluginDescriptionFile.h"
#include "servermanager/version.h"

PluginDescriptionFile::PluginDescriptionFile(const std::string &path)
{
	loaded = false;
	order = PluginLoadOrder::POSTWORLD;
	loadJson(path);
}

PluginDescriptionFile::PluginDescriptionFile(const std::string &pluginName, const std::string &pluginVersion)
{
	loaded = false;
	name = pluginName;
	version = pluginVersion;

	if(name.find(' ') != std::string::npos)
	{
		std::string findString = " ";
		name.replace(name.find(findString), findString.length(), "_");
	}
}

void PluginDescriptionFile::loadJson(const std::string &path)
{
	std::ifstream ifs(path, std::ifstream::binary);
	if(!ifs.is_open())
	{
		ifs.close();
		return;
	}

	Json::Value root;
	ifs >> root;
	ifs.close();

	if(!root.isMember("name") ||
			!root.isMember("version") ||
			!root.isMember("sm_version"))
		return;

	name = root.get("name", "").asString("");
	version = root.get("version", "").asString("");

	if(root.isArray())
	{
		for(Json::Value smVersion : root["sm_version"])
			smVersions.push_back(smVersion.asInt(0));
	}
	else
		smVersions.push_back(root.get("sm_version", 0).asInt(0));

	if(root.isMember("commands"))
	{
		if(!root["commands"].isObject())
			return;

		int cmdIndex = 0;
		Json::Value::Members cmdNames = root["commands"].getMemberNames();
		for(Json::Value command : root["commands"])
		{
			std::map<std::string, CommandDescValue> valueMap;
			if(command.isObject())
			{
				int cmdValueIndex = 0;
				Json::Value::Members cmdValueNames = command.getMemberNames();
				for(Json::Value commandEntry : command)
				{
					CommandDescValue value;
					if(commandEntry.isArray())
					{
						std::vector<std::string> subValues;
						for(Json::Value commandSubListItem : commandEntry)
							subValues.push_back(commandSubListItem.asString(""));

						value.isArray = true;
						value.arrayValue = subValues;
					}
					else
					{
						value.isArray = false;
						value.strValue = commandEntry.asString("");
					}
					valueMap[cmdValueNames[cmdValueIndex]] = value;

					cmdValueIndex++;
				}
			}
			commands[cmdNames[cmdIndex]] = valueMap;

			cmdIndex++;
		}
	}

	depend = makePluginNameList(root, "depend");
	softDepend = makePluginNameList(root, "softdepend");
	loadBefore = makePluginNameList(root, "loadbefore");

	website = root.get("website", "").asString("");
	description = root.get("description", "").asString("");

	std::string load = root.get("load", "").asString("");
	if(!load.compare("POSTWORLD"))
		order = PluginLoadOrder::POSTWORLD;
	else if(!load.compare("STARTUP"))
		order = PluginLoadOrder::STARTUP;

	if(root.isMember("author"))
		authors.push_back(root.get("author", "").asString(""));

	if(root.isMember("authors") && root["authors"].isArray())
		for(Json::Value author : root["authors"])
			authors.push_back(author.asString(""));

	prefix = root.get("prefix", "").asString("");

	loaded = true;
}

std::vector<std::string> PluginDescriptionFile::makePluginNameList(Json::Value root, const std::string &key)
{
	if(root.isMember(key) && root[key].isArray())
	{
		std::vector<std::string> list;
		for(Json::Value value : root[key])
			list.push_back(value.asString(""));

		return list;
	}
	return {};
}

bool PluginDescriptionFile::isLoaded() const
{
	return loaded;
}

const std::string &PluginDescriptionFile::getName() const
{
	return name;
}

const std::string &PluginDescriptionFile::getVersion() const
{
	return version;
}

std::vector<int> PluginDescriptionFile::getSMVersions() const
{
	return smVersions;
}

const std::string &PluginDescriptionFile::getDescription() const
{
	return description;
}

PluginLoadOrder PluginDescriptionFile::getLoad() const
{
	return order;
}

const std::vector<std::string> &PluginDescriptionFile::getAuthors() const
{
	return authors;
}

const std::string &PluginDescriptionFile::getWebsite() const
{
	return website;
}

const std::vector<std::string> &PluginDescriptionFile::getDepend() const
{
	return depend;
}

const std::vector<std::string> &PluginDescriptionFile::getSoftDepend() const
{
	return softDepend;
}

const std::vector<std::string> &PluginDescriptionFile::getLoadBefore() const
{
	return loadBefore;
}

const std::string &PluginDescriptionFile::getPrefix() const
{
	return prefix;
}

const std::map<std::string, std::map<std::string, PluginDescriptionFile::CommandDescValue>> &PluginDescriptionFile::getCommands() const
{
	return commands;
}

std::string PluginDescriptionFile::getFullName() const
{
	return name + " v" + version;
}
