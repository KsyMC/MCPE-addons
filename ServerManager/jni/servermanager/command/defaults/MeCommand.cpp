#include "servermanager/command/defaults/MeCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

MeCommand::MeCommand()
	: VanillaCommand("me")
{
	description = "Performs the specified action in chat";
	usageMessage = "%commands.me.usage";
}

bool MeCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if(args.size() < 1)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}
	ServerManager::broadcastMessage("* " + sender->getName() + " " + SMUtil::join(args, " "));

	return true;
}
