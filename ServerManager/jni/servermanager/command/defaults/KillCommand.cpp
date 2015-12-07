#include "KillCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"

#include "minecraftpe/Player.h"
#include "minecraftpe/EntityDamageSource.h"

KillCommand::KillCommand(std::string const &name)
	: Command(name,
			"Commit suicide or kill other players",
			"/kill [player]",
			{"suicide"}) {}

bool KillCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() > 1)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	if((int)args.size() == 1)
	{
		SMPlayer *player = sender->getServer()->getPlayer(args[0]);
		if(!player)
		{
			sender->sendMessage(TextContainer("commands.generic.player.notFound", true));
			return true;
		}

		player->get()->die(EntityDamageSource(CAUSE_SUICIDE));

		Command::broadcastCommandMessage(sender, TextContainer("commands.kill.successful", {player->getName()}));
	}
	else
	{
		sender->get()->die(EntityDamageSource(CAUSE_SUICIDE));
		sender->sendMessage(TextContainer("commands.kill.successful", {sender->getName()}));
	}

	return true;
}
