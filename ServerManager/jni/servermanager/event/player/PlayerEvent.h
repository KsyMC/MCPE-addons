#pragma once

#include "servermanager/event/Event.h"

class SMPlayer;

class PlayerEvent : public Event
{
protected:
	SMPlayer *player;

public:
	PlayerEvent(SMPlayer *who);

	SMPlayer *getPlayer() const;
};
