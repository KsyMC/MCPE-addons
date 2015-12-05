#include "TellCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"

TellCommand::TellCommand(std::string const &name)
	: Command(name,
			"Sends a private message to the given player",
			"%commands.message.usage",
			{"m", "msg"}) {}

bool TellCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() < 2)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	SMPlayer *player = sender->getServer()->getPlayer(args[0]);
	if(player == sender)
	{
		sender->sendMessage(TextContainer("§c%commands.message.sameTarget", true));
		return true;
	}

	std::vector<std::string> newArgs = args;
	newArgs.erase(newArgs.begin());

	std::string message = Command::implode(newArgs, " ");

	if(player)
	{
		sender->sendMessage(TextContainer("commands.message.display.outgoing", {player->getDisplayName(), message}));
		player->sendMessage(TextContainer("commands.message.display.incoming", {sender->getDisplayName(), message}));
	}
	else
		sender->sendMessage(TextContainer("commands.generic.player.notFound", true));

	return true;
}
