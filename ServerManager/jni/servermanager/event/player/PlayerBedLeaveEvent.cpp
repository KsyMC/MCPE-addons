#include "servermanager/event/player/PlayerBedLeaveEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerBedLeaveEvent::handlers = new HandlerList;

PlayerBedLeaveEvent::PlayerBedLeaveEvent(SMPlayer *who, FullBlock bed)
	: PlayerEvent(who)
{
	this->bed = bed;
}

FullBlock PlayerBedLeaveEvent::getBed() const
{
	return bed;
}

HandlerList *PlayerBedLeaveEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerBedLeaveEvent::getHandlerList()
{
	return handlers;
}
