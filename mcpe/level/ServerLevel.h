#ifndef __SERVERLEVEL_H__
#define __SERVERLEVEL_H__

#include "Level.h"

class ServerLevel : public Level {
public:
	// Size : 3064
	ServerLevel(Minecraft &, std::unique_ptr<LevelStorage>, const std::string &, const LevelSettings &);
	virtual ~ServerLevel();
	virtual void tick();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(int);
	bool allPlayersSleeping();
	void awakenAllPlayers();
};

#endif
