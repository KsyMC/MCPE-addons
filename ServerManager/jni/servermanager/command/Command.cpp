#include "servermanager/command/Command.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/command/CommandMap.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/resources/I18n.h"

Command::Command(const std::string &name, const std::string &description, const std::string &usageMessage, const std::vector<std::string> &aliases)
{
	commandMap = NULL;
	this->name = name;
	nextLabel = name;
	this->label = name;
	this->description = description;
	this->usageMessage = usageMessage.empty() ? "/" + name : usageMessage;
	this->aliases = aliases;
	activeAliases = aliases;
}

Command::~Command()
{
}

bool Command::isVanillaCommand() const
{
	return false;
}

bool Command::isPluginCommand() const
{
	return false;
}

std::string Command::getName() const
{
	return name;
}

std::string Command::getDescription() const
{
	return description;
}

void Command::setDescription(const std::string &description)
{
	this->description = description;
}

std::vector<std::string> Command::getAliases() const
{
	return activeAliases;
}

bool Command::setAliases(const std::vector<std::string> &aliases)
{
	this->aliases = aliases;
	if(!isRegistered())
		activeAliases = aliases;

	return true;
}

bool Command::registerCommand(CommandMap *commandMap)
{
	if(allowChangesFrom(commandMap))
	{
		this->commandMap = commandMap;
		return true;
	}
	return false;
}

bool Command::unregister(CommandMap *commandMap)
{
	if(allowChangesFrom(commandMap))
	{
		delete commandMap;
		commandMap = NULL;
		activeAliases = aliases;
		label = nextLabel;
		return true;
	}
	return false;
}

bool Command::isRegistered() const
{
	return commandMap != NULL;
}

bool Command::setLabel(const std::string &name)
{
	nextLabel = label;
	if(!isRegistered())
	{
		label = name;
		return true;
	}
	return false;
}

std::string Command::getLabel() const
{
	return label;
}

void Command::setUsage(const std::string &usage)
{
	usageMessage = usage;
}

std::string Command::getUsage() const
{
	return usageMessage;
}

void Command::broadcastCommandMessage(SMPlayer *source, const std::string &message, bool sendToSource)
{
	std::string newMessage = message;
	newMessage = "§7§o[" + source->getName() + ": " + (I18n::get(message).compare(message) ? "%" : "") + message + "]";

	for(SMPlayer *player : ServerManager::getLevel()->getPlayers())
	{
		if(player == source && !sendToSource)
			continue;

		player->sendMessage(newMessage);
	}
}

void Command::broadcastCommandTranslation(SMPlayer *source, const std::string &message, const std::vector<std::string> &params, bool sendToSource)
{
	std::string newMessage = message;
	newMessage = "§7§o[" + source->getName() + ": " + (I18n::get(message).compare(message) ? "%" : "") + message + "]";

	for(SMPlayer *player : ServerManager::getLevel()->getPlayers())
	{
		if(player == source && !sendToSource)
			continue;

		player->sendTranslation(newMessage, params);
	}
}

bool Command::allowChangesFrom(CommandMap *commandMap)
{
	return !this->commandMap || this->commandMap == commandMap;
}
