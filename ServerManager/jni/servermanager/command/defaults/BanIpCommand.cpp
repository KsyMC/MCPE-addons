#include <regex>

#include "BanIpCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMList.h"
#include "minecraftpe/Util.h"
#include "shared.h"

BanIpCommand::BanIpCommand(std::string const &name)
	: Command(name,
			"Prevents the specified IP address from using this server",
			"%commands.banip.usage") {}

bool BanIpCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	ServerManager *server = sender->getServer();

	std::string value = args[0];
	std::string reason;

	if((int)args.size() > 1)
	{
		std::vector<std::string> newArgs = args;
		newArgs.erase(newArgs.begin());

		reason = Util::stringTrim(Command::implode(newArgs, " "));
	}

	std::regex rx("\\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	if(std::regex_match(value, rx))
	{
		Command::broadcastCommandMessage(sender, TextContainer("commands.banip.success", {value}));
		processIPBan(value, server, reason);
	}
	else
	{
		SMPlayer *player = server->getPlayer(value);
		if(player && !player->isLocalPlayer())
		{
			Command::broadcastCommandMessage(sender, TextContainer("commands.banip.success.players", {player->getAddress(), player->getName()}));
			processIPBan(player->getAddress(), server, reason);
		}
		else
		{
			sender->sendMessage(TextContainer("commands.banip.invalid", true));
			return false;
		}
	}
	return true;
}

void BanIpCommand::processIPBan(std::string const &ip, ServerManager *server, std::string const &reason)
{
	SMList *banIpList = server->getBanIpList();
	banIpList->add(ip);
	banIpList->save();

	for(SMPlayer *player : server->getOnlinePlayers())
	{
		if(!player->getAddress().compare(ip))
			player->kick(!reason.empty() ? reason : "IP banned.");
	}
}
