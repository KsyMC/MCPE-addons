#include "servermanager/plugin/PluginBase.h"
#include "servermanager/Server.h"
#include "servermanager/command/PluginCommand.h"
#include "servermanager/plugin/PluginDescriptionFile.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/util/File.h"

PluginBase::PluginBase()
{
	enabled = false;
	server = NULL;
	description = NULL;
}

PluginBase::~PluginBase()
{
	delete description;
}

std::string PluginBase::getDataFolder()
{
	return dataFolder;
}

void PluginBase::onEnable()
{
}

void PluginBase::onDisable()
{
}

void PluginBase::onLoad()
{
}

std::string PluginBase::getName() const
{
	return getDescription()->getName();
}

PluginDescriptionFile *PluginBase::getDescription() const
{
	return description;
}

void PluginBase::saveConfig()
{

}

void PluginBase::saveDefaultConfig()
{

}

void PluginBase::saveResource(const std::string &resourcePath, bool replace)
{

}

void PluginBase::reloadConfig()
{

}

Server *PluginBase::getServer() const
{
	return server;
}

bool PluginBase::isEnabled() const
{
	return enabled;
}

void PluginBase::setEnabled(bool enabled)
{
	if(this->enabled == enabled)
		return;

	this->enabled = enabled;

	if(enabled)
		onEnable();
	else
		onDisable();
}

void PluginBase::init(Server *server, PluginDescriptionFile *description, const std::string &dataFolder)
{
	this->server = server;
	this->description = description;
	this->dataFolder = dataFolder;
	this->confingFile = dataFolder + "config.json";

	File::createFolder(dataFolder);
}

bool PluginBase::onCommand(SMPlayer *sender, Command *command, std::string &label, std::vector<std::string> &args)
{
	return false;
}

PluginCommand *PluginBase::getCommand(std::string &name)
{
	std::string alias = SMUtil::toLower(name);
	PluginCommand *command = getServer()->getPluginCommand(alias);

	if(!command || command->getPlugin() != this)
		command = getServer()->getPluginCommand(SMUtil::toLower(description->getName()) + ":" + alias);

	if(command && command->getPlugin() == this)
		return command;
	return NULL;
}
