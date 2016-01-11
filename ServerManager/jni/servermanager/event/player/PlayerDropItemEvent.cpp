#include "servermanager/event/player/PlayerDropItemEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerDropItemEvent::handlers = new HandlerList;

PlayerDropItemEvent::PlayerDropItemEvent(SMPlayer *player, ItemInstance *drop)
	: PlayerEvent(player)
{
	this->drop = drop;
	cancel = false;
}

ItemInstance *PlayerDropItemEvent::getItemDrop() const
{
	return drop;
}

bool PlayerDropItemEvent::isCancelled() const
{
	return cancel;
}

void PlayerDropItemEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerDropItemEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerDropItemEvent::getHandlerList()
{
	return handlers;
}
