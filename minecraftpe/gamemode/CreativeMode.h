#pragma once

#include "GameMode.h"

// Size : 32
class CreativeMode : public GameMode
{
public:
	CreativeMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual ~CreativeMode();
};
