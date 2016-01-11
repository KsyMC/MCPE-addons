#pragma once

#include "servermanager/event/entity/SMEntityEvent.h"
#include "servermanager/event/Cancellable.h"

class SMCreeper;

class CreeperPowerEvent : public SMEntityEvent, public Cancellable
{
public:
	enum PowerCause
	{
		LIGHTNING,
		SET_ON,
		SET_OFF
	};

private:
	static HandlerList *handlers;
	PowerCause cause;
	bool cancel;

public:
	CreeperPowerEvent(SMCreeper *creeper, PowerCause cause);

	SMCreeper *getEntity() const;

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
