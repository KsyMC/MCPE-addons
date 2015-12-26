#pragma once

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
	virtual void addParticle(ParticleType, Vec3 const &, Vec3 const &, int);
	virtual void playSound(string const &, Vec3 const &, float, float);
	virtual void playMusic(string const &, Vec3 const &, float);
	virtual void playStreamingMusic(string const &, int, int, int);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void levelEvent(LevelEvent, Vec3 const &, int);
};
