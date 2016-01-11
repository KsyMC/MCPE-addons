#include "servermanager/event/player/PlayerPickupItemEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerPickupItemEvent::handlers = new HandlerList;

PlayerPickupItemEvent::PlayerPickupItemEvent(SMPlayer *player, ItemInstance *item, int remaining)
	: PlayerEvent(player)
{
	this->item = item;
	this->remaining = remaining;
	cancel = false;
}

ItemInstance *PlayerPickupItemEvent::getItem() const
{
	return item;
}

int PlayerPickupItemEvent::getRemaining() const
{
	return remaining;
}

bool PlayerPickupItemEvent::isCancelled() const
{
	return cancel;
}

void PlayerPickupItemEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerPickupItemEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerPickupItemEvent::getHandlerList()
{
	return handlers;
}
