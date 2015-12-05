#include <regex>

#include "PardonIpCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMList.h"

PardonIpCommand::PardonIpCommand(std::string const &name)
	: Command(name,
			"Allows the specified IP address to use this server",
			"%commands.unbanip.usage") {}

bool PardonIpCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	std::regex rx("\\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	if(std::regex_match(args[0], rx))
	{
		SMList *banIpList = sender->getServer()->getBanIpList();
		banIpList->remove(args[0]);
		banIpList->save();

		Command::broadcastCommandMessage(sender, TextContainer("commands.unbanip.success", {args[0]}));
	}
	else
		sender->sendMessage(TextContainer("commands.unbanip.invalid"));

	return true;
}
