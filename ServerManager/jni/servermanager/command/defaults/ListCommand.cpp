#include "servermanager/command/defaults/ListCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

ListCommand::ListCommand()
	: VanillaCommand("list")
{
	description = "Lists all online players";
	usageMessage = "%commands.players.usage";
}

bool ListCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	std::string online;

	std::vector<SMPlayer *> players = ServerManager::getOnlinePlayers();
	for(size_t i = 0; i < players.size(); i++)
	{
		if(i > 0)
			online += ", ";

		SMPlayer *player = players[i];
		online += player->getDisplayName();
	}
	sender->sendTranslation("commands.players.list", {SMUtil::toString(players.size()), SMUtil::toString(ServerManager::getMaxPlayers())});
	sender->sendMessage(online);

	return true;
}
