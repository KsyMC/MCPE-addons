#include "GiveCommand.h"
#include "../../ServerManager.h"
#include "../../SMPlayer.h"
#include "minecraftpe/Item.h"
#include "minecraftpe/Block.h"
#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/Inventory.h"
#include "minecraftpe/Util.h"

GiveCommand::GiveCommand(std::string const &name)
	: Command(name,
			"Gives the specified player a certain amount of items",
			"%commands.give.usage") {}
#include "shared.h"
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

	std::string prefix = "minecraft:";
	std::string name = args[1];
	name.replace(name.find(prefix), prefix.length(), "");

	int id;

	Item *item = Item::lookupByName(args[1], true);
	if(!item)
	{
		Block *block = Block::lookupByName(args[1], true);
		if(!block)
		{
			if(Util::toInt(args[1], id))
			{
				sender->sendMessage(TextContainer("§c%commands.give.item.notFound", {args[1]}));
				return true;
			}
		}
		else
			id = block->id;
	}
	else
		id = item->id;

	int count = -1;
	int auxValue = 0;

	if((int)args.size() > 2)
		Util::toInt(args[2], count);

	if((int)args.size() > 3)
		Util::toInt(args[2], auxValue);

	if((int)args.size() > 4)// tag
	{
		sender->sendMessage(TextContainer("commands.give.tagError", {"Invalid tag conversion"}));
	}

	ItemInstance itemInst(id, count, auxValue);

	if(count == -1)
		itemInst.set(itemInst.getMaxStackSize());

	LOGI("%d %d %d", id, count, auxValue);
	player->getInventory()->add(itemInst);

	/*Command::broadcastCommandMessage(sender, TextContainer("%commands.give.success", {
		item->getName() + " (" + item->getId() + ":" + $item->getDamage() + ")",
		Util::toString(item->getCount()),
		player->getName()
	}));*/

	return true;
}
