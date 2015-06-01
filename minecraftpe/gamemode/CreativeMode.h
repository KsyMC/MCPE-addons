#pragma once

#include "GameMode.h"

// Size : 32
class CreativeMode : public GameMode
{
public:
	CreativeMode(PacketSender &, Level &, Vibration &);
	virtual ~CreativeMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void continueDestroyBlock(Player *, int, int, int, signed char);
	virtual void getPickRange();
	virtual void isCreativeType();
	virtual void initAbilities(Abilities &);
	virtual void releaseUsingItem(Player *);
};
