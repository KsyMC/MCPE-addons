#include "ListCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMUtil.h"

ListCommand::ListCommand(std::string const &name)
	: Command(name,
			"Lists all online players",
			"%commands.players.usage") {}

bool ListCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	ServerManager *server = sender->getServer();

	std::string online;
	int onlineCount = 0;

	std::vector<SMPlayer *> list = server->getOnlinePlayers();
	for(size_t i = 0; i < list.size(); i++)
	{
		SMPlayer *player = list[i];
		if(player->isOnline())
		{
			online += player->getDisplayName() + (i != (int)list.size() - 1 ? ", " : "");

			if(!player->isLocalPlayer())
				onlineCount++;
		}
	}

	sender->sendMessage(TextContainer("commands.players.list",
			{SMUtil::toString(onlineCount), SMUtil::toString(server->getMaxPlayers())}));

	sender->sendMessage(online);

	return true;
}
