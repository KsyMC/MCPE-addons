#include "KickCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "minecraftpe/Util.h"

KickCommand::KickCommand(std::string const &name)
	: Command(name,
			"Removes the specified player from the server",
			"%commands.kick.usage") {}

bool KickCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	std::string name = args[0];
	std::string reason;

	if((int)args.size() > 1)
	{
		std::vector<std::string> newArgs = args;
		newArgs.erase(newArgs.begin());

		reason = Util::stringTrim(Command::implode(newArgs, " "));
	}

	SMPlayer *player = sender->getServer()->getPlayer(name);
	if(!player || player->isLocalPlayer())
	{
		sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));
		return true;
	}

	if(!reason.empty())
		Command::broadcastCommandMessage(sender, TextContainer("commands.kick.success.reason", {player->getName(), reason}));
	else
		Command::broadcastCommandMessage(sender, TextContainer("commands.kick.success", {player->getName()}));

	player->kick(reason);

	return true;
}
