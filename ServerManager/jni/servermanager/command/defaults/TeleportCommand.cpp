#include "TeleportCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../utils/SMUtil.h"

#include "minecraftpe/Player.h"
#include "minecraftpe/Vec3.h"
#include "minecraftpe/Vec2.h"

TeleportCommand::TeleportCommand(std::string const &name)
	: Command(name,
			"Teleports the given player (or yourself) to another player or coordinates",
			"%commands.tp.usage") {}

bool TeleportCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() < 1 || (int)args.size() > 6)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	SMPlayer *target;
	SMPlayer *origin = sender;

	if((int)args.size() == 1 || (int)args.size() == 3)
	{
		target = sender;

		if((int)args.size() == 1)
		{
			target = sender->getServer()->getPlayer(args[0]);
			if(!target)
			{
				sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));
				return true;
			}
		}
	}
	else
	{
		target = sender->getServer()->getPlayer(args[0]);
		if(!target)
		{
			sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));
			return true;
		}

		if((int)args.size() == 2)
		{
			origin = target;
			target = sender->getServer()->getPlayer(args[1]);
			if(!target)
			{
				sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));
				return true;
			}
		}
	}

	if((int)args.size() < 3)
	{
		origin->teleport(target);
		Command::broadcastCommandMessage(sender, TextContainer("commands.tp.success", {origin->getName(), target->getName()}));

		return true;
	}
	else
	{
		int pos;

		if((int)args.size() == 4 || (int)args.size() == 6)
			pos = 1;
		else
			pos = 0;

		Vec3 position = target->get()->getPos();
		position.x = getRelativeDouble(position.x, sender, args[pos++]);
		position.y = getRelativeDouble(position.y, sender, args[pos++], 0, 128);
		position.z = getRelativeDouble(position.z, sender, args[pos++]);

		Vec2 rotation = target->get()->getRotation();
		if((int)args.size() == 6 || ((int)args.size() == 5 && pos == 3))
		{
			rotation.x = getDouble(sender, args[pos++]);
			rotation.y = getDouble(sender, args[pos++]);
		}
		target->teleport(position, rotation);

		Command::broadcastCommandMessage(sender, TextContainer("commands.tp.success.coordinates", {
				target->getName(),
				SMUtil::toString(round(position.x)), SMUtil::toString(round(position.y)), SMUtil::toString(round(position.z))}));

		return true;
	}

	sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));

	return true;
}
