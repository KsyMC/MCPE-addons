#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"
#include "servermanager/event/player/PlayerAnimationType.h"

class PlayerAnimationEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	PlayerAnimationType animationType;
	bool cancel;

public:
	PlayerAnimationEvent(SMPlayer *player, PlayerAnimationType animationType);

	PlayerAnimationType getAnimationType() const;

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
