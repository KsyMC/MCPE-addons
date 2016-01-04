#include "servermanager/command/defaults/PardonCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/client/resources/BanList.h"

PardonCommand::PardonCommand()
	: VanillaCommand("pardon")
{
	description = "Allows the specified player to use this server";
	usageMessage = "%commands.unban.usage";
}

bool PardonCommand::execute(SMPlayer *sender, std::string &commandLabel, std::vector<std::string> &args)
{
	if((int)args.size() != 1)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	ServerManager::getBanList(BanList::NAME)->pardon(args[0]);
	Command::broadcastCommandTranslation(sender, "commands.unban.success", {args[0]});

	return true;
}
