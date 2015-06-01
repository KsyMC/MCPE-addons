#pragma once

#include "GameMode.h"

class SoundPlayer;

// Size : 48
class SurvivalMode : public GameMode
{
public:
	char filler1[16];	// 32

public:
	SurvivalMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual ~SurvivalMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void continueDestroyBlock(Player *, int, int, int, signed char);
	virtual void stopDestroyBlock(Player *);
	virtual void canHurtPlayer();
	virtual void isSurvivalType();
	virtual void initAbilities(Abilities &);
};
