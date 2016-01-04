#include "servermanager/event/player/PlayerQuitEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerQuitEvent::handlers = new HandlerList;

PlayerQuitEvent::PlayerQuitEvent(SMPlayer *who, const std::string &quitMessage, const std::vector<std::string> &quitParams)
	: PlayerEvent(who)
{
	this->quitMessage;
	this->quitParams = quitParams;
}

const std::string &PlayerQuitEvent::getQuitMessage() const
{
	return quitMessage;
}

void PlayerQuitEvent::setQuitMessage(const std::string &quitMessage)
{
	this->quitMessage = quitMessage;
}

const std::vector<std::string> &PlayerQuitEvent::getQuitParams() const
{
	return quitParams;
}

void PlayerQuitEvent::setQuitParams(const std::vector<std::string> &quitParams)
{
	this->quitParams = quitParams;
}

HandlerList *PlayerQuitEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerQuitEvent::getHandlerList()
{
	return handlers;
}
