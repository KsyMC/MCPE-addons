#include "servermanager/event/player/PlayerChatEvent.h"
#include "servermanager/entity/SMPlayer.h"
#include "servermanager/event/HandlerList.h"
#include "servermanager/util/SMUtil.h"

HandlerList *PlayerChatEvent::handlers = new HandlerList;

PlayerChatEvent::PlayerChatEvent(SMPlayer *who, const std::string &message)
	: PlayerEvent(who)
{
	this->message = message;
	format = "<%s> %s";
	cancel = false;
}

const std::string &PlayerChatEvent::getMessage() const
{
	return message;
}

void PlayerChatEvent::setMessage(const std::string &message)
{
	this->message = message;
}

const std::string &PlayerChatEvent::getFormat() const
{
	return format;
}

void PlayerChatEvent::setFormat(const std::string &format)
{
	std::string result = SMUtil::format(format.c_str(), player->getDisplayName().c_str(), message.c_str());
	if(result.find("%s") != std::string::npos)
		return;

	this->format = format;
}

bool PlayerChatEvent::isCancelled() const
{
	return cancel;
}

void PlayerChatEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerChatEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerChatEvent::getHandlerList()
{
	return handlers;
}
