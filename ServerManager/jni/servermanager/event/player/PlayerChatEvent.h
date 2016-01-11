#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"

class PlayerChatEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	std::string message;
	std::string format;
	bool cancel;

public:
	PlayerChatEvent(SMPlayer *who, const std::string &message);

	const std::string &getMessage() const;
	void setMessage(const std::string &message);

	const std::string &getFormat() const;
	void setFormat(const std::string &format);

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
