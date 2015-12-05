#include "SimpleCommandMap.h"
#include "defaults/GameModeCommand.h"
#include "defaults/WhitelistCommand.h"
#include "defaults/HelpCommand.h"
#include "defaults/KickCommand.h"
#include "defaults/BanCommand.h"
#include "defaults/BanIpCommand.h"
#include "defaults/BanListCommand.h"
#include "defaults/PardonCommand.h"
#include "defaults/PardonIpCommand.h"
#include "defaults/OpCommand.h"
#include "defaults/DeopCommand.h"
#include "defaults/TellCommand.h"
#include "defaults/ListCommand.h"
#include "defaults/TimeCommand.h"
#include "defaults/GiveCommand.h"
#include "minecraftpe/Util.h"

SimpleCommandMap::SimpleCommandMap()
{
	setDefaultCommands();
}

SimpleCommandMap::~SimpleCommandMap()
{
	for(auto &e : knownCommands)
		delete e.second;

	knownCommands.clear();
}

bool SimpleCommandMap::registerCommand(Command *command, std::string const &label)
{
	std::string newLabel = label;

	if(newLabel.empty())
		newLabel = command->getName();
	newLabel = Util::toLower(Util::stringTrim(newLabel));

	bool registered = registerAlias(command, false, newLabel);

	std::vector<std::string> aliases = command->getAliases();
	for(auto it = aliases.begin(); it != aliases.end(); ++it)
	{
		if(!registerAlias(command, true, *it))
			aliases.erase(it);
	}
	command->setAliases(aliases);

	if(!registered)
		command->setLabel(newLabel);

	command->registerCommand(this);

	return registered;
}

bool SimpleCommandMap::dispatch(SMPlayer *sender, std::string const &cmdLine)
{
	std::vector<std::string> args = Util::split(cmdLine, ' ');
	if((int)args.size() == 0)
		return false;

	std::string sendCmdLabel = Util::toLower(args.front());
	Command *target = getCommand(sendCmdLabel);
	if(!target)
		return false;

	args.erase(args.begin());
	target->execute(sender, sendCmdLabel, args);

	return true;
}

bool SimpleCommandMap::registerAlias(Command *command, bool isAlias, std::string const &label)
{
	if(isAlias && knownCommands.find(label) != knownCommands.end())
		return false;

	if(knownCommands.find(label) != knownCommands.end() && !command->getLabel().compare(label))
		return false;

	if(!isAlias)
		command->setLabel(label);

	knownCommands[label] = command;

	return true;
}

void SimpleCommandMap::setDefaultCommands()
{
	registerCommand(new HelpCommand("help"));
	registerCommand(new GameModeCommand("gamemode"));
	registerCommand(new WhitelistCommand("whitelist"));
	registerCommand(new KickCommand("kick"));
	registerCommand(new BanCommand("ban"));
	registerCommand(new BanIpCommand("ban-ip"));
	registerCommand(new BanListCommand("banlist"));
	registerCommand(new PardonCommand("pardon"));
	registerCommand(new PardonIpCommand("pardon-ip"));
	registerCommand(new OpCommand("op"));
	registerCommand(new DeopCommand("deop"));
	registerCommand(new TellCommand("tell"));
	registerCommand(new ListCommand("list"));
	registerCommand(new TimeCommand("time"));
	registerCommand(new GiveCommand("give"));
}

void SimpleCommandMap::clearCommand()
{
	for(auto &e : knownCommands)
		e.second->unregisterCommand(this);

	knownCommands.clear();
	setDefaultCommands();
}

Command *SimpleCommandMap::getCommand(std::string const &name)
{
	if(knownCommands.find(name) != knownCommands.end())
		return knownCommands[name];

	return NULL;
}

std::map<std::string, Command *> SimpleCommandMap::getCommands()
{
	return knownCommands;
}
