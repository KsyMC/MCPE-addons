#include "servermanager/command/defaults/TeleportCommand.h"
#include "servermanager/ServerManager.h"
#include "servermanager/level/SMLevel.h"
#include "servermanager/entity/SMPlayer.h"
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

bool TeleportCommand::execute(SMPlayer *sender, std::string &commandLabel, std::vector<std::string> &args)
{
	if((int)args.size() < 1 || (int)args.size() > 6)
	{
		sender->sendTranslation("commands.generic.usage", {usageMessage});
		return false;
	}

	SMPlayer *target;
	SMPlayer *origin = sender;

	if((int)args.size() == 1 || (int)args.size() == 3)
	{
		target = (SMPlayer *)sender;

		if((int)args.size() == 1)
		{
			target = ServerManager::getLevel()->getPlayer(args[0]);
			if(!target)
			{
				sender->sendTranslation("§c%commands.generic.player.notFound", {});
				return true;
			}
		}
	}
	else
	{
		target = ServerManager::getLevel()->getPlayer(args[0]);
		if(!target)
		{
			sender->sendTranslation("§c%commands.generic.player.notFound", {});
			return true;
		}

		if((int)args.size() == 2)
		{
			origin = target;
			target = ServerManager::getLevel()->getPlayer(args[1]);
			if(!target)
			{
				sender->sendTranslation("§c%commands.generic.player.notFound", {});
				return true;
			}
		}
	}

	if((int)args.size() < 3)
	{
		origin->teleport(target);
		Command::broadcastCommandTranslation(sender, "commands.tp.success", {origin->getName(), target->getName()});

		return true;
	}
	else
	{
		int pos;

		if((int)args.size() == 4 || (int)args.size() == 6)
			pos = 1;
		else
			pos = 0;

		Vec3 position = target->getHandle()->getPos();
		position.x = getRelativeDouble(position.x, sender, args[pos++]);
		position.y = getRelativeDouble(position.y, sender, args[pos++], 0, 128);
		position.z = getRelativeDouble(position.z, sender, args[pos++]);

		Vec2 rotation = target->getHandle()->getRotation();
		if((int)args.size() == 6 || ((int)args.size() == 5 && pos == 3))
		{
			rotation.x = getDouble(sender, args[pos++]);
			rotation.y = getDouble(sender, args[pos++]);
		}
		target->teleport(position, rotation);

		Command::broadcastCommandTranslation(sender, "commands.tp.success.coordinates", {
				target->getName(),
				SMUtil::toString(round(position.x)),
				SMUtil::toString(round(position.y)),
				SMUtil::toString(round(position.z))
		});

		return true;
	}
	sender->sendTranslation("§c%commands.generic.player.notFound", {});

	return true;
}
