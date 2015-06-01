#pragma once

#include "Level.h"

class LevelSettings;

// Size : 3004
class MultiPlayerLevel : public Level
{
public:
	class ResetInfo
	{
	public:
		ResetInfo(int, int, int, int, int);
	};

public:
	MultiPlayerLevel(SoundPlayer &, const std::string &, const LevelSettings &);
	virtual ~MultiPlayerLevel();
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void tick();
	virtual void directTickEntities();
	void addToTickNextTick(int, int, int, int, int);
	void disconnect();
	Entity *getEntity(EntityUniqueID, bool);
	void putEntity(EntityUniqueID, std::unique_ptr<Entity>);
	void tickPendingTicks(bool);
};