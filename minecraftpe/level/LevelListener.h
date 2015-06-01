#pragma once

#include "TileSourceListener.h"
#include "ParticleType.h"

class LevelListener : public TileSourceListener
{
public:
	virtual ~LevelListener();
	virtual void allChanged();
	virtual void addParticle(ParticleType, const Vec3 &, const Vec3 &, int);
	virtual void playSound(const std::string &, float, float, float, float, float);
	virtual void playMusic(const std::string &, float, float, float, float);
	virtual void playStreamingMusic(const std::string &, int, int, int);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void levelEvent(LevelEvent, const Vec3 &, int);
};
