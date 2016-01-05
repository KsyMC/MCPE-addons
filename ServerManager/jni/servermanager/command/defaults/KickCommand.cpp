#include "servermanager/command/defaults/KickCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

KickCommand::KickCommand()
	: VanillaCommand("kick")
{
	description = "Removes the specified player from the server";
	usageMessage = "%commands.kick.usage";
}

bool KickCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() < 1 || args[0].empty())
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	SMPlayer *player = ServerManager::getLevel()->getPlayer(args[0]);

	std::vector<std::string> reasons = args;
	reasons.erase(args.begin());
	std::string reason = SMUtil::trim(SMUtil::join(reasons, " "));

	if(!player)
	{
		sender->sendTranslation("§c%commands.generic.player.notFound", {});
		return true;
	}

	if(!reason.empty())
		Command::broadcastCommandTranslation(sender, "commands.kick.success.reason", {player->getName(), reason});
	else
		Command::broadcastCommandTranslation(sender, "commands.kick.success", {player->getName()});

	ServerManager::kickPlayer(player, reason);

	return true;
}
