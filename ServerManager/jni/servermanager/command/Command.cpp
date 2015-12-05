#include <sstream>
#include <map>

#include "Command.h"
#include "../SMPlayer.h"
#include "../ServerManager.h"
#include "minecraftpe/I18n.h"
#include "minecraftpe/Util.h"

int Command::MAX_COORD = 30000000;
int Command::MIN_COORD = -30000000;

Command::Command(std::string const &name, std::string const &description, std::string const &usageMessage, std::vector<std::string> const &aliases)
{
	commandMap = NULL;
	this->name = name;
	this->label = name;
	this->description = description;
	this->usageMessage = usageMessage.empty() ? "/" + name : usageMessage;
	this->aliases = aliases;
	activeAliases = aliases;
}

Command::~Command()
{

}

std::string Command::getName() const
{
	return name;
}

std::string Command::getDescription() const
{
	return description;
}

std::vector<std::string> Command::getAliases() const
{
	return activeAliases;
}

void Command::setAliases(std::vector<std::string> const &aliases)
{
	this->aliases = aliases;
	if(!isRegistered())
		activeAliases = aliases;
}

void Command::unregisterCommand(CommandMap *commandMap)
{
	this->commandMap = NULL;
	activeAliases = aliases;
}

void Command::registerCommand(CommandMap *commandMap)
{
	this->commandMap = commandMap;
}

bool Command::isRegistered() const
{
	return commandMap != NULL;
}

void Command::setLabel(std::string const &label)
{
	this->label = label;
}

std::string Command::getLabel() const
{
	return label;
}

void Command::setUsage(std::string const &usage)
{
	usageMessage = usage;
}

std::string Command::getUsage() const
{
	return usageMessage;
}

std::string Command::implode(std::vector<std::string> const &v, std::string const &glue)
{
	std::stringstream ss;
	for(size_t i = 0; i < v.size(); ++i)
	{
		if(i != 0)
			ss << glue;
		ss << v[i];
	}
	return ss.str();
}

void Command::broadcastCommandMessage(SMPlayer *source, TextContainer const &message, bool sendToSource)
{
	TextContainer newMessage = message;
	newMessage.setText("§7§o[" + source->getName() + ": " + (I18n::get(message.getText()).compare(message.getText()) ? "%" : "") + message.getText() + "]");

	for(SMPlayer *player : source->getServer()->getOnlinePlayers())
	{
		if(player == source && !sendToSource)
			continue;

		player->sendMessage(newMessage);
	}
}

int Command::getInteger(SMPlayer *sender, std::string const &value, int min, int max) const
{
	int integer;

	int result = Util::toInt(value, integer, min, max);
	if(result == 1)
		integer = 1;
	else if(result == 2)
		integer = min;
	else if(result == 3)
		integer = max;

	return integer;
}
