#include "servermanager/event/player/PlayerLoginEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerLoginEvent::handlers = new HandlerList;

PlayerLoginEvent::PlayerLoginEvent(SMPlayer *player, const std::string &address, Result result, const std::string &message)
	: PlayerEvent(player)
{
	this->address = address;
	this->result = result;
	this->message = message;
}

PlayerLoginEvent::Result PlayerLoginEvent::getResult() const
{
	return result;
}

void PlayerLoginEvent::setResult(Result result)
{
	this->result = result;
}

const std::string &PlayerLoginEvent::getKickMessage() const
{
	return message;
}

void PlayerLoginEvent::setKickMessage(const std::string &message)
{
	this->message = message;
}

void PlayerLoginEvent::allow()
{
	result = Result::ALLOWED;
	message.clear();
}

void PlayerLoginEvent::disallow(Result result, const std::string &message)
{
	this->result = result;
	this->message = message;
}

const std::string &PlayerLoginEvent::getAddress() const
{
	return address;
}

HandlerList *PlayerLoginEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerLoginEvent::getHandlerList()
{
	return handlers;
}
