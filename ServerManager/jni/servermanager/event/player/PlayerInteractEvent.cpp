#include "servermanager/event/player/PlayerInteractEvent.h"
#include "servermanager/event/HandlerList.h"
#include "minecraftpe/item/ItemInstance.h"

HandlerList *PlayerInteractEvent::handlers = new HandlerList;

PlayerInteractEvent::PlayerInteractEvent(SMPlayer *who, Action action, ItemInstance *item, Block *clickedBlock, BlockFace clickedFace)
	: PlayerEvent(who)
{
	this->action = action;
	this->item = item;
	blockClicked = clickedBlock;
	blockFace = clickedFace;

	isUseItemInHand = EventResult::DEFAULT;
	useClickedBlock = !clickedBlock ? EventResult::DENY : EventResult::ALLOW;
}

Action PlayerInteractEvent::getAction() const
{
	return action;
}

ItemInstance *PlayerInteractEvent::getItem() const
{
	return item;
}

bool PlayerInteractEvent::hasBlock() const
{
	return blockClicked != NULL;
}

bool PlayerInteractEvent::hasItem() const
{
	return item != NULL;
}

bool PlayerInteractEvent::isBlockInHand() const
{
	if(!hasItem())
		return false;

	return item->block != NULL;
}

Block *PlayerInteractEvent::getClickedBlock() const
{
	return blockClicked;
}

BlockFace PlayerInteractEvent::getBlockFace() const
{
	return blockFace;
}

Event::EventResult PlayerInteractEvent::useInteractedBlock() const
{
	return useClickedBlock;
}

void PlayerInteractEvent::setUseInteractedBlock(EventResult useInteractedBlock)
{
	useClickedBlock = useInteractedBlock;
}

Event::EventResult PlayerInteractEvent::useItemInHand() const
{
	return isUseItemInHand;
}

void PlayerInteractEvent::setUseItemInHand(EventResult useItemInHand)
{
	this->isUseItemInHand = useItemInHand;
}

bool PlayerInteractEvent::isCancelled() const
{
	return useInteractedBlock() == EventResult::DENY;
}

void PlayerInteractEvent::setCancelled(bool cancel)
{
	setUseInteractedBlock(cancel ? EventResult::DENY : (useInteractedBlock() == EventResult::DENY ? EventResult::DEFAULT : useInteractedBlock()));
}

HandlerList *PlayerInteractEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerInteractEvent::getHandlerList()
{
	return handlers;
}
