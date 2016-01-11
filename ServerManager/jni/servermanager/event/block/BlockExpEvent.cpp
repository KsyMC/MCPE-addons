#include "servermanager/event/block/BlockExpEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *BlockExpEvent::handlers = new HandlerList;

BlockExpEvent::BlockExpEvent(Block *block, int exp)
	: BlockEvent(block)
{
	this->exp = exp;
}

int BlockExpEvent::getExpToDrop() const
{
	return exp;
}

void BlockExpEvent::setExpToDrop(int exp)
{
	this->exp = exp;
}

HandlerList *BlockExpEvent::getHandlers() const
{
	return handlers;
}

HandlerList *BlockExpEvent::getHandlerList()
{
	return handlers;
}
