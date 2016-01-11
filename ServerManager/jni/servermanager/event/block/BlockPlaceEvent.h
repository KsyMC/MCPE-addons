#pragma once

#include "servermanager/event/block/BlockEvent.h"
#include "servermanager/event/Cancellable.h"
#include "minecraftpe/item/ItemInstance.h"

class Player;

class BlockPlaceEvent : public BlockEvent, public Cancellable
{
public:
	class BlockState {};

private:
	static HandlerList *handlers;

protected:
	bool build;
	Block *placedAgainst;
	BlockState replacedBlockState;
	ItemInstance itemInHand;
	Player *player;
	bool cancel;

public:
	BlockPlaceEvent(Block *placedBlock, BlockState replacedBlockState, Block *placedAgainst, ItemInstance itemInHand, Player *thePlayer, bool build);

	bool isCancelled() const;
	void setCancelled(bool cancel);

	Player *getPlayer() const;
	Block *getBlockPlaced() const;
	BlockState getBlockReplacedState() const;
	Block *getBlockAgainst() const;
	ItemInstance getItemInHand() const;

	bool canBuild() const;
	void setBuild(bool build);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
