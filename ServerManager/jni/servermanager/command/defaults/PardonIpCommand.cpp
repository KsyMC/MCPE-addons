#include <regex>

#include "servermanager/command/defaults/PardonIpCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"

PardonIpCommand::PardonIpCommand()
	: VanillaCommand("pardon-ip")
{
	description = "Allows the specified IP address to use this server";
	usageMessage = "%commands.unbanip.usage";
}

bool PardonIpCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() != 1)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	std::regex rx("\\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	if(std::regex_match(args[0], rx))
	{
		ServerManager::unbanIP(args[0]);
		Command::broadcastCommandTranslation(sender, "commands.unbanip.success", {args[0]});
	}
	else
		sender->sendTranslation("commands.unbanip.invalid", {});

	return true;
}
