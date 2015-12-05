#include "OpCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"

OpCommand::OpCommand(std::string const &name)
	: Command(name,
			"Gives the specified player operator status",
			"%commands.op.usage") {}

bool OpCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	ISMPlayer *player = sender->getServer()->getOfflinePlayer(args[0]);
	player->setOp(true);

	Command::broadcastCommandMessage(sender, TextContainer("commands.op.success", {player->getName()}));

	if(player->isOnline())
		player->getPlayer()->sendMessage(TextContainer("§7You are now op!"));
	else
		delete player;

	return true;
}
