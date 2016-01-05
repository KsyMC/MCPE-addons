#include <cmath>

#include "servermanager/command/defaults/HelpCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/command/CommandMap.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/client/resources/I18n.h"

HelpCommand::HelpCommand()
	: VanillaCommand("help")
{
	description = "Shows the help menu";
	usageMessage = "%commands.help.usage";
	setAliases({"?"});
}

bool HelpCommand::execute(SMPlayer *sender, std::string &commandLabel, std::vector<std::string> &args)
{
	std::string command;
	int pageNumber = 1;
	int pageHeight = 5;

	if((int) args.size() >= 1)
	{
		if(SMUtil::is_number(args[0]))
		{
			pageNumber = getInteger(sender, args[0], 1);
			if(pageNumber < 1)
				pageNumber = 1;
		}
		else
			command = SMUtil::join(args, " ");
	}

	if(command.empty())
	{
		struct comp
		{
			bool operator() (const std::string &left, const std::string &right) const
			{
				return left <right;
			}
		};

		std::map<std::string, Command *, comp> commandList;

		for(auto &key : ServerManager::getServer()->getCommandMap()->getCommands())
		{
			Command *command = key.second;
			commandList[command->getName()] = command;
		}
		int pages = (int)ceil((int)commandList.size() / (float)pageHeight);

		std::vector<Command *> sortCommands;
		for(auto &key : commandList)
			sortCommands.push_back(key.second);

		pageNumber = std::min(pages, pageNumber);

		sender->sendTranslation("commands.help.header", {SMUtil::toString(pageNumber), SMUtil::toString(pages)});

		int startIndex = pageHeight * (pageNumber - 1);
		for(int i = startIndex; i < startIndex + pageHeight; i++)
		{
			if(i >= sortCommands.size())
				break;

			Command *command = sortCommands[i];
			sender->sendTranslation("§2#" + command->getName() + ": §f" + command->getDescription(), {});
		}
		return true;
	}
	else
	{
		Command *cmd = ServerManager::getServer()->getCommandMap()->getCommand(command);
		if(cmd)
		{
			std::string message;
			message += "§e--------- §fHelp: #" + cmd->getName() + " §e---------\n";
			message += "§6Description: §f" + cmd->getDescription() + "\n";
			message += "§6Usage: §f" + SMUtil::join(SMUtil::split(cmd->getUsage(), '\n'), "\n§f") + "\n";
			sender->sendMessage(message);
		}
		else
			sender->sendMessage("§cNo help for " + SMUtil::toLower(command));

		return true;
	}
}
