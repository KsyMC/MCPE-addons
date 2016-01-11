#pragma once

#include "servermanager/event/player/PlayerEvent.h"
#include "servermanager/event/Cancellable.h"
#include "minecraftpe/gamemode/GameType.h"

class PlayerGameModeChangeEvent : public PlayerEvent, public Cancellable
{
private:
	static HandlerList *handlers;
	GameType gametype;
	bool cancel;

public:
	PlayerGameModeChangeEvent(SMPlayer *player, GameType newGameType);

	GameType getNewGameType();

	bool isCancelled() const;
	void setCancelled(bool cancel);

	HandlerList *getHandlers() const;
	static HandlerList *getHandlerList();
};
