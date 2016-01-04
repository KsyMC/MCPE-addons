#pragma once

#include "servermanager/event/player/PlayerEvent.h"

class PlayerJoinEvent : public PlayerEvent
{
private:
	static HandlerList *handlers;
	std::string joinMessage;

public:
	PlayerJoinEvent(SMPlayer *playerJoined, const std::string &joinMessage);

	const std::string &getJoinMessage() const;
	void setJoinMessage(const std::string &joinMessage);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
