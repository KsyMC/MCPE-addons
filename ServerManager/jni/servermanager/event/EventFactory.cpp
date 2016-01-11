#include <memory>
#include <string>

#include "servermanager/ServerManager.h"
#include "servermanager/block/SMBlock.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/event/EventFactory.h"
#include "servermanager/plugin/PluginManager.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/level/BlockSource.h"

std::unique_ptr<PlayerInteractEvent> EventFactory::callPlayerInteractEvent(Player *who, Action action, ItemInstance *itemInHand)
{
	std::unique_ptr<PlayerInteractEvent> event;

	if(action != Action::LEFT_CLICK_AIR && action != Action::RIGHT_CLICK_AIR)
		return event;
	event = std::move(callPlayerInteractEvent(who, action, 0, 256, 0, 0, itemInHand));

	return event;
}

std::unique_ptr<PlayerInteractEvent> EventFactory::callPlayerInteractEvent(Player *who, Action action, int clickedX, int clickedY, int clickedZ, int clickedFace, ItemInstance *itemInHand)
{
	SMPlayer *player = !who ? NULL : (SMPlayer *)ServerManager::getEntity(who);

	Block *blockClicked = who->getRegion()->getBlock(clickedX, clickedY, clickedZ);
	BlockFace blockFace = SMBlock::notchToBlockFace(clickedFace);

	if(clickedY > 255)
	{
		blockClicked = NULL;
		switch(action)
		{
		case Action::LEFT_CLICK_BLOCK:
			action = Action::LEFT_CLICK_AIR;
			break;
		case Action::RIGHT_CLICK_BLOCK:
			action = Action::RIGHT_CLICK_AIR;
			break;
		}
	}

	if(itemInHand->getId() == 0 || itemInHand->count == 0)
		itemInHand = NULL;

	std::unique_ptr<PlayerInteractEvent> event = std::unique_ptr<PlayerInteractEvent>(new PlayerInteractEvent(player, action, itemInHand, blockClicked, blockFace));
	player->getServer()->getPluginManager()->callEvent(*event.get());

	return event;
}
