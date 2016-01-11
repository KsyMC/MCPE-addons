#pragma once

#include <vector>

#include "servermanager/event/block/BlockEvent.h"
#include "servermanager/event/Cancellable.h"

class SMPlayer;

class SignChangeEvent : public BlockEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	SMPlayer *player;
	std::vector<std::string> lines;
	bool cancel;

public:
	SignChangeEvent(Block *theBlock, SMPlayer *thePlayer, const std::vector<std::string> &theLines);

	SMPlayer *getPlayer() const;
	const std::vector<std::string> &getLines() const;
	const std::string &getLines(int index) const;

	void setLine(int index, const std::string &line);

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
