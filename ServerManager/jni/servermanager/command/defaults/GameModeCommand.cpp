#include "servermanager/command/defaults/GameModeCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/util/SMUtil.h"

GameModeCommand::GameModeCommand()
	: VanillaCommand("gamemode")
{
	description = "Changes the player to a specific game mode";
	usageMessage = "%commands.gamemode.usage";
}

bool GameModeCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if(args.empty())
	{
		sender->sendTranslation("§c%commands.generic.usage", {usageMessage});
		return false;
	}

	std::string modeArg = args[0];
	std::string playerArg = sender->getName();

	if((int)args.size() >= 2)
		playerArg = args[1];

	SMPlayer *player = ServerManager::getLevel()->getPlayer(playerArg);
	if(!player)
	{
		sender->sendTranslation("commands.generic.player.notFound", {});
		return false;
	}

	GameType gametype = Server::getGamemodeFromString(args[0]);
	if(gametype == -1)
	{
		sender->sendMessage("Unknown game mode");
		return true;
	}

	if(player->getGameType() == gametype)
	{
		sender->sendMessage(player->getName() + " already has game mode " + SMUtil::toString(gametype));
		return true;
	}
	player->setGameType(gametype);

	if(gametype != player->getGameType())
		sender->sendMessage("Game mode change for " + player->getName() + " failed!");
	else
	{
		if(sender == player)
			Command::broadcastCommandTranslation(sender, "commands.gamemode.success.self", {Server::getGamemodeString(gametype)});
		else
			Command::broadcastCommandTranslation(sender, "commands.gamemode.success.other", {player->getName(), Server::getGamemodeString(gametype)});
	}
	return true;
}
