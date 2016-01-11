#include "servermanager/event/block/BlockBreakEvent.h"

BlockBreakEvent::BlockBreakEvent(Block *theBlock, Player *player)
	: BlockExpEvent(theBlock, 0)
{
	this->player = player;
	cancel = false;
}

Player *BlockBreakEvent::getPlayer() const
{
	return player;
}

bool BlockBreakEvent::isCancelled() const
{
	return cancel;
}

void BlockBreakEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}
