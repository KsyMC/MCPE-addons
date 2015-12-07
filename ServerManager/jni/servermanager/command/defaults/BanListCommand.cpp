#include "BanListCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMList.h"
#include "../../utils/SMUtil.h"

BanListCommand::BanListCommand(std::string const &name)
	: Command(name,
			"View all players banned from this server",
			"%commands.banlist.usage") {}

bool BanListCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	ServerManager *server = sender->getServer();
	SMList *banList;

	std::string arg;
	if(args.size() >= 1)
	{
		arg = SMUtil::toLower(args[0]);
		if(!arg.compare("ips"))
			banList = server->getBanIpList();
		else if(!arg.compare("players"))
			banList = server->getBanList();
		else
		{
			sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
			return false;
		}
	}
	else
	{
		banList = server->getBanList();
		arg = "players";
	}

	std::string message;

	std::vector<std::string> list = banList->getAll();
	int size = (int)list.size();

	std::vector<std::string>::size_type i;
	for(i = 0; i < size; i++)
		message += list[i] + (i != size - 1 ? ", " : "");

	if(!arg.compare("ips"))
		sender->sendMessage(TextContainer("commands.banlist.ips", {SMUtil::toString(size)}));
	else if(!arg.compare("players"))
		sender->sendMessage(TextContainer("commands.banlist.players", {SMUtil::toString(size)}));

	if(!message.empty())
		sender->sendMessage(TextContainer(message));

	return true;
}
