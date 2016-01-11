#include "servermanager/event/player/PlayerGameModeChangeEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerGameModeChangeEvent::handlers = new HandlerList;

PlayerGameModeChangeEvent::PlayerGameModeChangeEvent(SMPlayer *player, GameType newGameType)
	: PlayerEvent(player)
{
	gametype = newGameType;
	cancel = false;
}

GameType PlayerGameModeChangeEvent::getNewGameType()
{
	return gametype;
}

bool PlayerGameModeChangeEvent::isCancelled() const
{
	return cancel;
}

void PlayerGameModeChangeEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerGameModeChangeEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerGameModeChangeEvent::getHandlerList()
{
	return handlers;
}
