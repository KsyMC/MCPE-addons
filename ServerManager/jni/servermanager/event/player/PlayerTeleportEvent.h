#pragma once

#include "servermanager/event/player/PlayerMoveEvent.h"

class PlayerTeleportEvent : public PlayerMoveEvent
{
public:
	enum TeleportCause
	{
		ENDER_PEARL,
		COMMAND,
		PLUGIN,
		NETHER_PORTAL,
		END_PORTAL,
		UNKNOWN
	};

private:
	static HandlerList *handlers;
	TeleportCause cause;

public:
	PlayerTeleportEvent(SMPlayer *player, const Location &from, const Location &to, TeleportCause cause = UNKNOWN);

	TeleportCause getCause() const;

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
