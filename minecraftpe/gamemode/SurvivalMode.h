#pragma once

#include "minecraftpe/gamemode/GameMode.h"

class SurvivalMode : public GameMode {
public:
	SurvivalMode(Minecraft *);
	virtual ~SurvivalMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void countinueDestoryBlock(Player *, int, int, int, signed char);
	virtual void stopDestroyBlock(Player *, int, int, int, signed char);
	virtual bool canHurtPlayer();
	virtual bool isSurvivalType();
	virtual void initAbilities(Abilities &);
};
