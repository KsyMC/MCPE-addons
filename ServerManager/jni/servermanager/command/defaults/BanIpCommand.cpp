#include <regex>

#include "servermanager/command/defaults/BanIpCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/client/resources/BanList.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

BanIpCommand::BanIpCommand()
	: VanillaCommand("ban-ip")
{
	description = "Prevents the specified IP address from using this server",
	usageMessage = "%commands.banip.usage";
}

bool BanIpCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() < 1)
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	std::string nameOrIP = args[0];

	args.erase(args.begin());
	std::string reason = SMUtil::trim(SMUtil::join(args, " "));

	std::regex rx("\\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	if(std::regex_match(nameOrIP, rx))
	{
		Command::broadcastCommandTranslation(sender, "commands.banip.success", {nameOrIP});
		processIPBan(nameOrIP, sender, reason);
	}
	else
	{
		SMPlayer *player = ServerManager::getLevel()->getPlayer(nameOrIP);
		if(!player)
		{
			sender->sendTranslation("§c%commands.banip.invalid", {});
			return false;
		}

		std::string ip = player->getAddress();

		Command::broadcastCommandTranslation(sender, "commands.banip.success.players", {ip, player->getName()});
		processIPBan(ip, sender, reason);
	}
	return true;
}

void BanIpCommand::processIPBan(const std::string &ip, SMPlayer *source, const std::string &reason)
{
	ServerManager::getBanList(BanList::IP)->addBan(ip, reason, source->getName());

	for(SMPlayer *p : ServerManager::getLevel()->getPlayers())
		if(!ip.compare(p->getAddress()))
			ServerManager::kickPlayer(p, "You have been IP banned.");
}
