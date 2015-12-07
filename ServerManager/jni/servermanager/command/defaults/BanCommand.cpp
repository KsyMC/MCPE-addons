#include "BanCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMUtil.h"

BanCommand::BanCommand(std::string const &name)
	: Command(name,
			"Prevents the specified player from using this server",
			"%commands.ban.usage") {}

bool BanCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() == 0)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	std::string name = args[0];
	std::string reason;

	std::vector<std::string> newArgs = args;
	newArgs.erase(newArgs.begin());

	reason = SMUtil::trim(SMUtil::join(newArgs, " "));

	ServerManager *server = sender->getServer();
	SMPlayer *player = server->getPlayerExact(name);

	server->addBanned(name);

	Command::broadcastCommandMessage(sender, TextContainer("commands.ban.success", {player ? player->getName() : name}));

	if(player && !player->isLocalPlayer())
		player->kick(!reason.empty() ? "Banned by admin. Reason: " + reason : "Banned by admin.");

	return true;
}
