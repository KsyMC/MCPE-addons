#include <sstream>
#include <map>

#include "Command.h"
#include "../SMPlayer.h"
#include "../ServerManager.h"
#include "../utils/SMUtil.h"

#include "minecraftpe/I18n.h"

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
	int result = SMUtil::toInt(value);

	if(result < min)
		result = min;
	else if(result > max)
		result = max;

	return result;
}

double Command::getRelativeDouble(double original, SMPlayer *sender, std::string const &input, double min, double max) const
{
	if(input[0] == '~')
		return original + getDouble(sender, input, min, max);
	return getDouble(sender, input, min, max);
}

double Command::getDouble(SMPlayer *sender, std::string const &value, double min, double max) const
{
	double result = SMUtil::toDouble(value.c_str());

	if(result < min)
		result = min;
	else if(result > max)
		result = max;

	return result;
}
