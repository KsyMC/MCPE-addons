#include "servermanager/command/defaults/TeleportCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/entity/SMEntity.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/event/player/PlayerTeleportEvent.h"
#include "servermanager/util/SMUtil.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"

TeleportCommand::TeleportCommand()
	: VanillaCommand("tp")
{
	description = "Teleports the given player (or yourself) to another player or coordinates";
	usageMessage = "%commands.tp.usage";
}

bool TeleportCommand::execute(SMPlayer *sender, std::string &label, std::vector<std::string> &args)
{
	if((int)args.size() < 1 || (int)args.size() > 4)
	{
		sender->sendTranslation("commands.generic.usage", {usageMessage});
		return false;
	}

	SMPlayer *player;

	if((int)args.size() == 1 || (int)args.size() == 3)
		player = sender;
	else
		player = ServerManager::getPlayer(args[0]);

	if(!player)
	{
		sender->sendTranslation("§c%commands.generic.player.notFound", {});
		return true;
	}

	if((int)args.size() < 3)
	{
		SMPlayer *target = ServerManager::getPlayer(args[args.size() - 1]);
		if(!target)
		{
			sender->sendTranslation("§c%commands.generic.player.notFound", {});
			return true;
		}
		player->SMEntity::teleport(target, PlayerTeleportEvent::COMMAND);
		Command::broadcastCommandTranslation(sender, "commands.tp.success", {player->getDisplayName(), target->getDisplayName()});
	}
	else if(player->getRegion())
	{
		Location playerLocation = player->getLocation();
		double x = getCoordinate(sender, playerLocation.getX(), args[args.size() - 3]);
		double y = getCoordinate(sender, playerLocation.getY(), args[args.size() - 2], 0, 0);
		double z = getCoordinate(sender, playerLocation.getZ(), args[args.size() - 1]);

		playerLocation.setX(x);
		playerLocation.setY(y);
		playerLocation.setZ(z);

		player->teleport(playerLocation, PlayerTeleportEvent::COMMAND);

		Command::broadcastCommandTranslation(sender, "commands.tp.success.coordinates", {player->getDisplayName(),
				SMUtil::format("%.2f", x), SMUtil::format("%.2f", y), SMUtil::format("%.2f", z)});
	}
	return true;
}

double TeleportCommand::getCoordinate(SMPlayer *sender, double current, std::string &input, int max, int min)
{
	bool relative = input[0] == '~';
	double result = relative ? current : 0;

	if(!relative || input.length() > 1)
	{
		bool exact = input.find('.') != std::string::npos;
		if(relative)
			input = input.erase(0, 1);

		result += SMUtil::toDouble(input);

		if(!exact && !relative)
			result += 0.5f;
	}

	if(min != 0 || min != 0)
	{
		if(result < min)
			result = MIN_COORD_MINUS_ONE;

		if(result > max)
			result = MIN_COORD_MINUS_ONE;
	}

	return result;
}
