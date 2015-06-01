#pragma once

#include "Level.h"

// Size : 2996
class ServerLevel : public Level
{
public:
	ServerLevel(SoundPlayer &, std::unique_ptr<LevelStorage>, const std::string &, const LevelSettings &);
	virtual ~ServerLevel();
	virtual void tick();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(int);
	bool allPlayersSleeping();
	void awakenAllPlayers();
};