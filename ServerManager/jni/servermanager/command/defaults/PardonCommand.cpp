#include "PardonCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMList.h"

PardonCommand::PardonCommand(std::string const &name)
	: Command(name,
			"Allows the specified player to use this server",
			"%commands.unban.usage") {}

bool PardonCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	sender->getServer()->removeBanned(args[0]);

	Command::broadcastCommandMessage(sender, TextContainer("commands.unban.success", {args[0]}));

	return true;
}
