#pragma once

#include <vector>

#include "servermanager/event/player/PlayerEvent.h"

class PlayerQuitEvent : public PlayerEvent
{
private:
	static HandlerList *handlers;
	std::string quitMessage;
	std::vector<std::string> quitParams;

public:
	PlayerQuitEvent(SMPlayer *who, const std::string &quitMessage, const std::vector<std::string> &quitParams);

	const std::string &getQuitMessage() const;
	void setQuitMessage(const std::string &quitMessage);

	const std::vector<std::string> &getQuitParams() const;
	void setQuitParams(const std::vector<std::string> &quitParams);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
