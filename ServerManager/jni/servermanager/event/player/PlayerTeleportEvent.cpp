#include "servermanager/event/player/PlayerTeleportEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerTeleportEvent::handlers = new HandlerList;

PlayerTeleportEvent::PlayerTeleportEvent(SMPlayer *player, const Location &from, const Location &to, TeleportCause cause)
	: PlayerMoveEvent(player, from, to)
{
	this->cause = cause;
}

PlayerTeleportEvent::TeleportCause PlayerTeleportEvent::getCause() const
{
	return cause;
}

HandlerList *PlayerTeleportEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerTeleportEvent::getHandlerList()
{
	return handlers;
}
