#include "servermanager/event/player/PlayerAnimationEvent.h"
#include "servermanager/event/HandlerList.h"

HandlerList *PlayerAnimationEvent::handlers = new HandlerList;

PlayerAnimationEvent::PlayerAnimationEvent(SMPlayer *player, PlayerAnimationType animationType)
	: PlayerEvent(player)
{
	this->animationType = animationType;
	cancel = false;
}

PlayerAnimationType PlayerAnimationEvent::getAnimationType() const
{
	return animationType;
}

bool PlayerAnimationEvent::isCancelled() const
{
	return cancel;
}

void PlayerAnimationEvent::setCancelled(bool cancel)
{
	this->cancel = cancel;
}

HandlerList *PlayerAnimationEvent::getHandlers() const
{
	return handlers;
}

HandlerList *PlayerAnimationEvent::getHandlerList()
{
	return handlers;
}
