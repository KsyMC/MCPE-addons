#include "servermanager/event/player/PlayerEvent.h"

PlayerEvent::PlayerEvent(SMPlayer *who)
{
	player = who;
}

SMPlayer *PlayerEvent::getPlayer() const
{
	return player;
}
