#pragma once

#include "Level.h"
#include "Difficulty.h"

// Size : 2996
class ServerLevel : public Level
{
public:
	ServerLevel(SoundPlayer &, std::unique_ptr<LevelStorage>, std::string const&, LevelSettings const &);
	virtual void ~ServerLevel();
	virtual void tick();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	bool allPlayersSleeping();
	void awakenAllPlayers();
};
