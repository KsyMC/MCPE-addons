#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"

class ItemInstance;

class PlayerPickupItemEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	ItemInstance *item;
	int remaining;
	bool cancel;

public:
	PlayerPickupItemEvent(SMPlayer *player, ItemInstance *item, int remaining);

	ItemInstance *getItem() const;
	int getRemaining() const;

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
