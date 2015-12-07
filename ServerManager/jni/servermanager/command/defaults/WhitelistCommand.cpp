#include "WhitelistCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMList.h"
#include "../../utils/SMOptions.h"
#include "../../utils/SMUtil.h"

WhitelistCommand::WhitelistCommand(std::string const &name)
	: Command(name,
			"Manages the list of players allowed to use this server",
			"%commands.whitelist.usage") {}

bool WhitelistCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0 || (int)args.size() > 2)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return true;
	}

	ServerManager *server = sender->getServer();
	if(!args[0].compare("on"))
	{
		if(!server->hasWhitelist())
			server->getOptions()->toggleWhitelist();

		Command::broadcastCommandMessage(sender, TextContainer("commands.whitelist.enabled", true));

		return true;
	}
	else if(!args[0].compare("off"))
	{
		if(server->hasWhitelist())
			server->getOptions()->toggleWhitelist();

		Command::broadcastCommandMessage(sender, TextContainer("commands.whitelist.disabled", true));

		return true;
	}
	else if(!args[0].compare("add"))
	{
		if((int)args.size() < 2)
		{
			sender->sendMessage(TextContainer("commands.whitelist.add.usage", true));
			return true;
		}

		std::string name = args[1];

		ISMPlayer *player = server->getOfflinePlayer(name);
		player->setWhitelisted(true);

		Command::broadcastCommandMessage(sender, TextContainer("commands.whitelist.add.success", {player->getName()}));

		if(!player->isOnline())
			delete player;

		return true;
	}
	else if(!args[0].compare("remove"))
	{
		if((int)args.size() < 2)
		{
			sender->sendMessage(TextContainer("commands.whitelist.remove.usage", true));
			return true;
		}

		std::string name = args[1];

		ISMPlayer *player = server->getOfflinePlayer(name);
		player->setWhitelisted(false);

		Command::broadcastCommandMessage(sender, TextContainer("commands.whitelist.remove.success", {name}));

		if(!player->isOnline())
			delete player;

		return true;
	}
	else if(!args[0].compare("list"))
	{
		std::string result;

		std::vector<std::string> list = server->getWhitelistList()->getAll();
		int size = (int)list.size();

		std::vector<std::string>::size_type i;
		for(i = 0; i < size; i++)
			result += list[i] + (i != size - 1 ? ", " : "");

		sender->sendMessage(TextContainer("commands.whitelist.list", {SMUtil::toString(size), SMUtil::toString(size)}));

		if(!result.empty())
			sender->sendMessage(TextContainer(result));

		return true;
	}
	else if(!args[0].compare("reload"))
	{
		server->reloadWhitelist();
		Command::broadcastCommandMessage(sender, TextContainer("commands.whitelist.reloaded", true));

		return true;
	}
	sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));

	return true;
}
