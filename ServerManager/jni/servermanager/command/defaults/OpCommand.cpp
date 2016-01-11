#include "servermanager/command/defaults/OpCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"

OpCommand::OpCommand()
	: VanillaCommand("op")
{
	description = "Gives the specified player's operator status";
	usageMessage = "%commands.op.usage";
}

bool OpCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() != 1 || args[0].empty())
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	ServerManager::getServer()->addOp(args[0]);

	SMPlayer *player = ServerManager::getPlayerExact(args[0]);
	if(player)
		player->sendMessage("§7You are now op!");

	Command::broadcastCommandTranslation(sender, "commands.op.success", {args[0]});

	return true;
}
