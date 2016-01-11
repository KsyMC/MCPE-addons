#pragma once

#include "servermanager/event/block/BlockExpEvent.h"
#include "servermanager/event/Cancellable.h"

class Player;

class BlockBreakEvent : public BlockExpEvent, public Cancellable
{
private:
	Player *player;
	bool cancel;

public:
	BlockBreakEvent(Block *theBlock, Player *player);

	Player *getPlayer() const;

	bool isCancelled() const;
	void setCancelled(bool cancel);
};
