#include "GiveCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "../../level/SMLevel.h"
#include "../../utils/SMUtil.h"

#include "minecraftpe/Item.h"
#include "minecraftpe/Block.h"
#include "minecraftpe/Player.h"
#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/Inventory.h"
#include "minecraftpe/Vec3.h"

GiveCommand::GiveCommand(std::string const &name)
	: Command(name,
			"Gives the specified player a certain amount of items",
			"%commands.give.usage") {}

bool GiveCommand::execute(SMPlayer *sender, std::string const &commandLabel, std::vector<std::string> const &args)
{
	if((int)args.size() < 2)
	{
		sender->sendMessage(TextContainer("commands.generic.usage", {usageMessage}));
		return false;
	}

	SMPlayer *player = sender->getServer()->getPlayer(args[0]);
	if(!player)
	{
		sender->sendMessage(TextContainer("§c%commands.generic.player.notFound", true));
		return true;
	}

	std::string name = args[1];

	std::string prefix = "minecraft:";
	if(name.find(prefix) != std::string::npos)
		name.replace(name.find(prefix), prefix.length(), "");

	int id;

	Item *item = Item::lookupByName(name, true);
	if(!item)
	{
		Block *block = Block::lookupByName(name, true);
		if(!block)
		{
			if(!SMUtil::is_number(name))
			{
				sender->sendMessage(TextContainer("§c%commands.give.item.notFound", {args[1]}));
				return true;
			}
			else
				id = SMUtil::toInt(name);
		}
		else
			id = block->id;
	}
	else
		id = item->id;

	int count = 0;
	int auxValue = 0;

	if((int)args.size() > 2 && SMUtil::toInt(args[2]))
		count = SMUtil::toInt(args[2]);

	if((int)args.size() > 3 && SMUtil::toInt(args[3]))
		auxValue = SMUtil::toInt(args[3]);

	if((int)args.size() > 4)// tag
	{
		sender->sendMessage(TextContainer("commands.give.tagError", {"Invalid tag conversion"}));
	}

	ItemInstance itemInst(id, count, auxValue);

	if(count == 0)
	{
		count = itemInst.getMaxStackSize();
		itemInst.set(count);
	}

	sender->getLevel()->dropItem(player, player->get()->getPos(), itemInst, 0);

	Command::broadcastCommandMessage(sender, TextContainer("commands.give.success",
			{itemInst.getName() + " (" + SMUtil::toString(itemInst.getId()) + ":"
					+ SMUtil::toString(itemInst.getAuxValue()) + ")"
					+ SMUtil::toString(count), player->getName()}));

	return true;
}
