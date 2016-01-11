#pragma once

#include "minecraftpe/gamemode/GameMode.h"

class CreativeMode : public GameMode
{
public:
	CreativeMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual ~CreativeMode();
};
