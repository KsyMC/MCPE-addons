#include <cmath>

#include "HelpCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../SimpleCommandMap.h"
#include "minecraftpe/Util.h"
#include "minecraftpe/I18n.h"

HelpCommand::HelpCommand(std::string const &name)
	: Command(name,
			"Shows the help menu",
			"%commands.help.usage",
			{"?"}) {}

struct comp
{
	bool operator() (const std::string &left, const std::string &right) const
	{
		return left<right;
	}
};

bool HelpCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	std::string command;
	int pageNumber = 1;
	int pageHeight = 5;

	if((int)args.size() >= 1)
	{
		int number;
		if(!Util::toInt(args[0], number))
		{
			pageNumber = number;
			if(pageNumber <= 0)
				pageNumber = 1;
		}
		else
			command = Command::implode(args, " ");
	}

	if(command.empty())
	{
		std::map<std::string, Command *, comp> commandList;

		for(auto &key : ((SimpleCommandMap *)sender->getServer()->getCommandMap())->getCommands())
		{
			Command *command = key.second;
			commandList[command->getName()] = command;
		}
		int pages = (int)ceil((int)commandList.size() / (float)pageHeight);

		std::vector<Command *> sortCommands;
		for(auto &key : commandList)
			sortCommands.push_back(key.second);

		pageNumber = std::min(pages, pageNumber);
		if(pageNumber < 1)
			pageNumber = 1;

		sender->sendMessage(TextContainer("commands.help.header", {Util::toString(pageNumber), Util::toString(pages)}));

		int startIndex = pageHeight * (pageNumber - 1);
		for(int i = startIndex; i < startIndex + pageHeight; i++)
		{
			if(i >= sortCommands.size())
				break;

			Command *command = sortCommands[i];
			sender->sendMessage(TextContainer("§2/" + command->getName() + ": §f" + command->getDescription()));
		}
		return true;
	}
	else
	{
		Command *cmd = ((SimpleCommandMap *)sender->getServer()->getCommandMap())->getCommand(command);
		if(cmd)
		{
			std::string message;
			message += "§e--------- §fHelp: /" + cmd->getName() + " §e---------\n";
			message += "§6Description: §f" + cmd->getDescription() + "\n";
			message += "§6Usage: §f" + Command::implode(Util::split(cmd->getUsage(), '\n'), "\n§f") + "\n";
			sender->sendMessage(TextContainer(message));
		}
		else
			sender->sendMessage(TextContainer("§cNo help for " + Util::toLower(command)));

		return true;
	}
}
