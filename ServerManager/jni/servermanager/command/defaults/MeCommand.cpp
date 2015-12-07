#include "MeCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMUtil.h"

MeCommand::MeCommand(std::string const &name)
	: Command(name,
			"Performs the specified action in chat",
			"%commands.me.usage") {}

bool MeCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	sender->getServer()->broadcastMessage(TextContainer("chat.type.emote", {sender->getDisplayName(), SMUtil::join(args, " ")}));

	return true;
}
