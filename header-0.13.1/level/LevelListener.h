#pragma once

#include <string>

#include "minecraftpe/level/BlockSourceListener.h"
#include "minecraftpe/level/ParticleType.h"
#include "minecraftpe/event/LevelEvent.h"

class Vec3;
class Entity;
class LevelChunk;
class Player;

class LevelListener : public BlockSourceListener
{
public:
	virtual ~LevelListener();
	virtual void allChanged();
	virtual void addParticle(ParticleType, const Vec3 &, const Vec3 &, int);
	virtual void playSound(const std::string &, const Vec3 &, float, float);
	virtual void playMusic(const std::string &, const Vec3 &, float);
	virtual void playStreamingMusic(const std::string &, int, int, int);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void levelEvent(LevelEvent, const Vec3 &, int);
};
