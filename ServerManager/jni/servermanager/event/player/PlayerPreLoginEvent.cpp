#include "servermanager/event/player/PlayerPreLoginEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerPreLoginEvent::handlers = new HandlerList;

PlayerPreLoginEvent::PlayerPreLoginEvent(const std::string &name, const std::string &ipAddress, mce::UUID uuid)
{
	this->result = Result::ALLOWED;
	this->name = name;
	this->ipAddress = ipAddress;
	this->uuid = uuid;
}

PlayerPreLoginEvent::Result PlayerPreLoginEvent::getResult() const
{
	return result;
}

void PlayerPreLoginEvent::setResult(Result result)
{
	this->result = result;
}

std::string PlayerPreLoginEvent::getKickMessage()
{
	return message;
}

void PlayerPreLoginEvent::setKickMessage(const std::string &message)
{
	this->message = message;
}

void PlayerPreLoginEvent::allow()
{
	result = Result::ALLOWED;
	message.clear();
}

void PlayerPreLoginEvent::disallow(Result result, const std::string &message)
{
	this->result = result;
	this->message = message;
}

const std::string &PlayerPreLoginEvent::getName() const
{
	return name;
}

const std::string &PlayerPreLoginEvent::getAddress() const
{
	return ipAddress;
}

mce::UUID PlayerPreLoginEvent::getUUID() const
{
	return uuid;
}

HandlerList *PlayerPreLoginEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerPreLoginEvent::getHandlerList()
{
	return handlers;
}
