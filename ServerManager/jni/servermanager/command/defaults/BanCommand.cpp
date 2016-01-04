#include "servermanager/command/defaults/BanCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/client/resources/BanList.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"
#include "servermanager/level/SMLevel.h"

BanCommand::BanCommand()
	: VanillaCommand("ban")
{
	description = "Prevents the specified player from using this server";
	usageMessage = "%commands.ban.usage";
}

bool BanCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if(args.empty())
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	args.erase(args.begin());
	std::string reason = SMUtil::trim(SMUtil::join(args, " "));

	ServerManager::getBanList(BanList::NAME)->addBan(args[0], reason, sender->getName());

	Command::broadcastCommandTranslation(sender, "commands.ban.success", {args[0]});

	SMPlayer *player = ServerManager::getLevel()->getPlayer(args[0]);
	if(player)
		ServerManager::kickPlayer(player, "Banned by admin.");

	return true;
}
