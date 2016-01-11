#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"
#include "minecraftpe/block/FullBlock.h"

class PlayerBedEnterEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	FullBlock bed;
	bool cancel;

public:
	PlayerBedEnterEvent(SMPlayer *who, FullBlock bed);

	FullBlock getBed() const;

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
