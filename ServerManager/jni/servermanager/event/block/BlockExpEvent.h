#pragma once

#include "servermanager/event/block/BlockEvent.h"

class BlockExpEvent : public BlockEvent
{
private:
	static HandlerList *handlers;
	int exp;

public:
	BlockExpEvent(Block *block, int exp);

	int getExpToDrop() const;
	void setExpToDrop(int exp);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
