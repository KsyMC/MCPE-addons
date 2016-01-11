#pragma once

#include "servermanager/event/Event.h"
#include "minecraftpe/util/UUID.h"

class PlayerPreLoginEvent : public Event
{
public:
	enum Result
	{
		ALLOWED,
		KICK_BANNED,
		KICK_WHITELIST,
		KICK_INVALID_NAME,
		KICK_INVALID_SKIN,
		KICK_OTHER
	};

private:
	static HandlerList *handlers;
	Result result;
	std::string message;
	std::string name;
	std::string ipAddress;
	mce::UUID uuid;

public:
	PlayerPreLoginEvent(const std::string &name, const std::string &ipAddress, mce::UUID uuid);

	Result getResult() const;
	void setResult(Result result);

	std::string getKickMessage();
	void setKickMessage(const std::string &message);

	void allow();
	void disallow(Result result, const std::string &message);

	const std::string &getName() const;
	const std::string &getAddress() const;
	mce::UUID getUUID() const;

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
