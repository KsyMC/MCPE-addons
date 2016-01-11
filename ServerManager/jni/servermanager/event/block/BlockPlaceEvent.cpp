#include "servermanager/event/block/BlockPlaceEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *BlockPlaceEvent::handlers = new HandlerList;

BlockPlaceEvent::BlockPlaceEvent(Block *placedBlock, BlockState replacedBlockState, Block *placedAgainst, ItemInstance itemInHand, Player *thePlayer, bool build)
	: BlockEvent(placedBlock)
{
	this->placedAgainst = placedAgainst;
	this->itemInHand = itemInHand;
	this->player = player;
	this->replacedBlockState = replacedBlockState;
	this->build = build;
	cancel = false;
}

bool BlockPlaceEvent::isCancelled() const
{
	return cancel;
}

void BlockPlaceEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

Player *BlockPlaceEvent::getPlayer() const
{
	return player;
}

Block *BlockPlaceEvent::getBlockPlaced() const
{
	return getBlock();
}

BlockPlaceEvent::BlockState BlockPlaceEvent::getBlockReplacedState() const
{
	return replacedBlockState;
}

Block *BlockPlaceEvent::getBlockAgainst() const
{
	return placedAgainst;
}

ItemInstance BlockPlaceEvent::getItemInHand() const
{
	return itemInHand;
}

bool BlockPlaceEvent::canBuild() const
{
	return build;
}

void BlockPlaceEvent::setBuild(bool build)
{
	this->build = build;
}

HandlerList *BlockPlaceEvent::getHandlers() const
{
	return handlers;
}

HandlerList *BlockPlaceEvent::getHandlerList()
{
	return handlers;
}
