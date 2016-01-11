#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"
#include "servermanager/event/block/Action.h"
#include "servermanager/block/BlockFace.h"

class ItemInstance;
class Block;

class PlayerInteractEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	ItemInstance *item;
	Action action;
	Block *blockClicked;
	BlockFace blockFace;
	EventResult useClickedBlock;
	EventResult isUseItemInHand;

public:
	PlayerInteractEvent(SMPlayer *who, Action action, ItemInstance *item, Block *clickedBlock, BlockFace clickedFace);

	Action getAction() const;
	ItemInstance *getItem() const;

	bool hasBlock() const;
	bool hasItem() const;
	bool isBlockInHand() const;

	Block *getClickedBlock() const;
	BlockFace getBlockFace() const;

	EventResult useInteractedBlock() const;
	void setUseInteractedBlock(EventResult useInteractedBlock);

	EventResult useItemInHand() const;
	void setUseItemInHand(EventResult useItemInHand);

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
