#include "servermanager/event/player/PlayerCommandPreprocessEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerCommandPreprocessEvent::handlers = new HandlerList;

PlayerCommandPreprocessEvent::PlayerCommandPreprocessEvent(SMPlayer *player, const std::string &message)
	: PlayerEvent(player)
{
	this->message = message;
	cancel = false;
}

const std::string &PlayerCommandPreprocessEvent::getMessage() const
{
	return message;
}

void PlayerCommandPreprocessEvent::setMessage(const std::string &command)
{
	this->message = message;
}

void PlayerCommandPreprocessEvent::setPlayer(SMPlayer *player)
{
	this->player = player;
}

bool PlayerCommandPreprocessEvent::isCancelled() const
{
	return cancel;
}

void PlayerCommandPreprocessEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerCommandPreprocessEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerCommandPreprocessEvent::getHandlerList()
{
	return handlers;
}
