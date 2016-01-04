#include "servermanager/command/CommandMap.h"
#include "servermanager/Server.h"
#include "servermanager/command/defaults/GameModeCommand.h"
#include "servermanager/command/defaults/WhitelistCommand.h"
#include "servermanager/command/defaults/HelpCommand.h"
#include "servermanager/command/defaults/KickCommand.h"
#include "servermanager/command/defaults/BanCommand.h"
#include "servermanager/command/defaults/BanIpCommand.h"
#include "servermanager/command/defaults/BanListCommand.h"
#include "servermanager/command/defaults/PardonCommand.h"
#include "servermanager/command/defaults/PardonIpCommand.h"
#include "servermanager/command/defaults/OpCommand.h"
#include "servermanager/command/defaults/DeopCommand.h"
#include "servermanager/command/defaults/TellCommand.h"
#include "servermanager/command/defaults/ListCommand.h"
#include "servermanager/command/defaults/TimeCommand.h"
#include "servermanager/command/defaults/GiveCommand.h"
#include "servermanager/command/defaults/TeleportCommand.h"
#include "servermanager/command/defaults/MeCommand.h"
#include "servermanager/command/defaults/KillCommand.h"
#include "servermanager/util/SMUtil.h"

CommandMap::CommandMap()
{
	setDefaultCommands();
}

CommandMap::~CommandMap()
{
	for(Command *cmd : commands)
		delete cmd;

	knownCommands.clear();
	commands.clear();
}

void CommandMap::setDefaultCommands()
{
	registerCommand("servermanager", new HelpCommand);
	registerCommand("servermanager", new GameModeCommand);
	registerCommand("servermanager", new WhitelistCommand);
	registerCommand("servermanager", new KickCommand);
	registerCommand("servermanager", new BanCommand);
	registerCommand("servermanager", new BanIpCommand);
	registerCommand("servermanager", new BanListCommand);
	registerCommand("servermanager", new PardonCommand);
	registerCommand("servermanager", new PardonIpCommand);
	registerCommand("servermanager", new OpCommand);
	registerCommand("servermanager", new DeopCommand);
	registerCommand("servermanager", new TellCommand);
	registerCommand("servermanager", new ListCommand);
	registerCommand("servermanager", new TimeCommand);
	registerCommand("servermanager", new GiveCommand);
	registerCommand("servermanager", new TeleportCommand);
	registerCommand("servermanager", new MeCommand);
	registerCommand("servermanager", new KillCommand);
}

void CommandMap::setFallbackCommands()
{

}

void CommandMap::registerAll(const std::string &fallbackPrefix, std::vector<Command *> commands)
{
	if(!commands.empty())
	{
		for(Command *c : commands)
			registerCommand(fallbackPrefix, c);
	}
}

bool CommandMap::registerCommand(const std::string &fallbackPrefix, Command *command)
{
	return registerCommand(command->getName(), fallbackPrefix, command);
}

bool CommandMap::registerCommand(const std::string &label, const std::string &fallbackPrefix, Command *command)
{
	std::string newLabel = SMUtil::toLower(SMUtil::trim(label));
	std::string newFallbackPrefix = SMUtil::toLower(SMUtil::trim(fallbackPrefix));

	bool registered = registerCommand(newLabel, command, false, newFallbackPrefix);

	std::vector<std::string> aliases = command->getAliases();
	for(auto it = aliases.begin(); it != aliases.end(); ++it)
	{
		if(!registerCommand(*it, command, true, newFallbackPrefix))
			it = aliases.erase(it);
	}

	if(!registered)
		command->setLabel(newFallbackPrefix + ":" + newLabel);

	command->registerCommand(this);

	return registered;
}

bool CommandMap::registerCommand(const std::string &label, Command *command, bool isAlias, const std::string &fallbackPrefix)
{
	knownCommands[fallbackPrefix + ":" + label] = command;
	if((command->isVanillaCommand() || isAlias) && knownCommands.find(label) != knownCommands.end())
		return false;

	if(knownCommands.find(label) != knownCommands.end() && !command->getLabel().compare(label))
		return false;

	if(!isAlias)
	{
		commands.push_back(command);
		command->setLabel(label);
	}
	knownCommands[label] = command;

	return true;
}

bool CommandMap::dispatch(SMPlayer *sender, const std::string &cmdLine)
{
	std::vector<std::string> args = SMUtil::split(cmdLine, ' ');
	if(args.empty())
		return false;

	std::string sentCommandLabel = SMUtil::toLower(args.front());
	Command *target = getCommand(sentCommandLabel);

	if(!target)
		return false;

	args.erase(args.begin());
	target->execute(sender, sentCommandLabel, args);

	return true;
}

void CommandMap::clearCommands()
{
	for(auto &it : knownCommands)
		it.second->unregister(this);

	for(Command *cmd : commands)
		delete cmd;

	knownCommands.clear();
	commands.clear();
	setDefaultCommands();
}

Command *CommandMap::getCommand(const std::string &name)
{
	std::string lname = SMUtil::toLower(name);
	if(knownCommands.find(lname) != knownCommands.end())
		return knownCommands[lname];

	return NULL;
}

const std::map<std::string, Command *> &CommandMap::getCommands() const
{
	return knownCommands;
}
