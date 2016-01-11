#pragma once

#include "servermanager/event/player/PlayerEvent.h"

class PlayerLoginEvent : public PlayerEvent
{
public:
	enum Result
	{
		ALLOWED,
		KICK_FULL,
		KICK_BANNED,
		KICK_WHITELIST,
		KICK_INVALID_NAME,
		KICK_INVALID_SKIN,
		KICK_OTHER
	};

private:
	static HandlerList *handlers;
	std::string address;
	Result result;
	std::string message;

public:
	PlayerLoginEvent(SMPlayer *player, const std::string &address = "", Result result = ALLOWED, const std::string &message = "");

	Result getResult() const;
	void setResult(Result result);

	const std::string &getKickMessage() const;
	void setKickMessage(const std::string &message);

	void allow();
	void disallow(Result result, const std::string &message);

	const std::string &getAddress() const;

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
