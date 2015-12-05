#include "DeopCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"

DeopCommand::DeopCommand(std::string const &name)
	: Command(name,
			"Takes the specified player's operator status",
			"%commands.deop.usage") {}

bool DeopCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	ISMPlayer *player = sender->getServer()->getOfflinePlayer(args[0]);
	player->setOp(false);

	if(player->isOnline())
		player->getPlayer()->sendMessage(TextContainer("§7You are no longer op!"));

	Command::broadcastCommandMessage(sender, TextContainer("commands.deop.success", {player->getName()}));

	return true;
}
