#include "servermanager/command/defaults/WhitelistCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/SMList.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

WhitelistCommand::WhitelistCommand()
	: VanillaCommand("whitelist")
{
	description = "Manages the list of players allowed to use this server";
	usageMessage = "%commands.whitelist.usage";
}

bool WhitelistCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if(args.empty() || (int)args.size() > 2)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return true;
	}

	if((int)args.size() == 1)
	{
		if(!args[0].compare("reload"))
		{
			ServerManager::reloadWhitelist();
			Command::broadcastCommandTranslation(sender, "commands.whitelist.reloaded", {});

			return true;
		}
		else if(!args[0].compare("on"))
		{
			ServerManager::setWhitelist(true);
			Command::broadcastCommandTranslation(sender, "commands.whitelist.enabled", {});

			return true;
		}
		else if(!args[0].compare("off"))
		{
			ServerManager::setWhitelist(false);
			Command::broadcastCommandTranslation(sender, "commands.whitelist.disabled", {});

			return true;
		}
		else if(!args[0].compare("list"))
		{
			std::string result;

			std::vector<std::string> players = ServerManager::getWhitelist()->getAll();
			for(size_t i = 0; i < players.size(); i++)
			{
				if(i > 0)
					result += ", ";

				result += players[i];
			}
			sender->sendTranslation("commands.whitelist.list", {SMUtil::toString(players.size()), SMUtil::toString(players.size())});
			sender->sendMessage(result);

			return true;
		}
	}
	else if((int) args.size() == 2)
	{
		if(!args[0].compare("add"))
		{
			ServerManager::getWhitelist()->add(args[1]);
			Command::broadcastCommandTranslation(sender, "commands.whitelist.add.success", {args[1]});

			return true;
		}
		else if(!args[0].compare("remove"))
		{
			ServerManager::getWhitelist()->remove(args[1]);
			Command::broadcastCommandTranslation(sender, "commands.whitelist.remove.success", {args[1]});

			return true;
		}
	}
	sender->sendTranslation("commands.generic.usage", {usageMessage});

	return false;
}
