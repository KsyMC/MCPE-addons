#include "servermanager/command/defaults/TellCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

TellCommand::TellCommand()
	: VanillaCommand("tell")
{
	description = "Sends a private message to the given player",
	usageMessage = "%commands.message.usage",
	setAliases({"w", "msg"});
}

bool TellCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() < 2)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	SMPlayer *player = ServerManager::getLevel()->getPlayer(args[0]);
	if(sender == player)
	{
		sender->sendTranslation("§c%commands.message.sameTarget", {});
		return true;
	}

	if(!player)
	{
		sender->sendTranslation("§c%commands.generic.player.notFound", {});
		return true;
	}

	args.erase(args.begin());
	std::string message = SMUtil::join(args, " ");

	sender->sendTranslation("commands.message.display.outgoing", {player->getName(), message});
	player->sendTranslation("commands.message.display.incoming", {player->getName(), message});

	return true;
}
