#include "servermanager/event/player/PlayerMoveEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerMoveEvent::handlers = new HandlerList;

PlayerMoveEvent::PlayerMoveEvent(SMPlayer *player, const Location &from, const Location &to)
	: PlayerEvent(player)
{
	this->from = from;
	this->to = to;
	cancel = false;
}

const Location &PlayerMoveEvent::getFrom() const
{
	return from;
}

void PlayerMoveEvent::setForm(const Location &form)
{
	this->from = from;
}

const Location &PlayerMoveEvent::getTo() const
{
	return to;
}

void PlayerMoveEvent::setTo(const Location &to)
{
	this->to = to;
}

bool PlayerMoveEvent::isCancelled() const
{
	return cancel;
}

void PlayerMoveEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerMoveEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerMoveEvent::getHandlerList()
{
	return handlers;
}
