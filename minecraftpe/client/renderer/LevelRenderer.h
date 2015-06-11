#pragma once

#include <memory>
#include "../../level/LevelListener.h"
#include "../AppPlatformListener.h"
#include "texture/TextureAtlas.h"

class MinecraftClient;

// Size : 1240
class LevelRenderer : public LevelListener, public AppPlatformListener
{
public:
	LevelRenderer(MinecraftClient *, std::shared_ptr<TextureAtlas>);
	virtual ~LevelRenderer();
	virtual void onAreaChanged(TileSource &, const TilePos &, const TilePos &);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual void onBrightnessChanged(TileSource&, const TilePos &);
	virtual void allChanged();
	virtual void addParticle(ParticleType, const Vec3 &, const Vec3 &, int);
	virtual void playSound(const std::string &, float, float, float, float, float);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void levelEvent(LevelEvent, const Vec3 &, int);
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onLowMemory();
};
