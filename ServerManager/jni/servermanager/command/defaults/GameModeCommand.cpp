#include "GameModeCommand.h"
#include "../../SMPlayer.h"
#include "../../ServerManager.h"
#include "minecraftpe/Level.h"
#include "shared.h"

GameModeCommand::GameModeCommand(std::string const &name)
	: Command(name,
			"Changes the player to a specific game mode",
			"%commands.gamemode.usage",
			{"gm"}) {}

bool GameModeCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	int gameMode = ServerManager::getGamemodeFromString(args[0]);
	if(gameMode == -1)
	{
		sender->sendMessage(TextContainer("Unknown game mode"));
		return true;
	}

	SMPlayer *target = sender;
	if((int)args.size() >= 2)
	{
		std::string name = args[1];
		target = sender->getServer()->getPlayer(name);
		if(!target)
		{
			sender->sendMessage(TextContainer("commands.generic.player.notFound", true));
			return true;
		}
	}
	target->setGamemode(gameMode);

	if(gameMode != target->getGamemode())
		sender->sendMessage("Game mode change for " + target->getName() + " failed!");
	else
	{
		if(target == sender)
			Command::broadcastCommandMessage(sender, TextContainer("commands.gamemode.success.self", {ServerManager::getGamemodeString(gameMode)}));
		else
		{
			target->sendMessage(TextContainer("gameMode.changed", true));
			Command::broadcastCommandMessage(sender, TextContainer("commands.gamemode.success.other", {target->getName(), ServerManager::getGamemodeString(gameMode)}));
		}
	}
	return true;
}
