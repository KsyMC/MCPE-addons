#include "servermanager/command/defaults/BanListCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/BanList.h"
#include "servermanager/BanEntry.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

BanListCommand::BanListCommand()
	: VanillaCommand("banlist")
{
	description = "View all players banned from this server",
	usageMessage = "%commands.banlist.usage";
}

bool BanListCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	BanList::Type banType = BanList::NAME;
	if(args.size() > 0)
	{
		if(!args[0].compare("ips"))
			banType = BanList::IP;
		else if(args[0].compare("players"))
		{
			sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
			return false;
		}
	}

	std::string message;
	std::vector<BanEntry *> banList = ServerManager::getBanList(banType)->getBanEntries();

	for(size_t i = 0; i < banList.size(); i++)
	{
		if(i != 0)
		{
			if(i == (int)banList.size() - 1)
				message += " and ";
			else
				message += ", ";
		}

		message += banList[i]->getTarget();
	}

	if(banType == BanList::IP)
		sender->sendTranslation("commands.banlist.ips", {SMUtil::toString(banList.size())});
	else if(banType == BanList::NAME)
		sender->sendTranslation("commands.banlist.players", {SMUtil::toString(banList.size())});

	sender->sendMessage(message);

	return true;
}
