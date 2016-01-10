#pragma once

#include <memory>
#include "BlockSourceListener.h"
#include "AppPlatformListener.h"
#include "Difficulty.h"
#include "Player.h"

class Dimension;
class LightLayer;
class LevelChunk;
class LevelStorage;
class EntityDamageSource;

class Level : public BlockSourceListener, public AppPlatformListener
{
public:
	virtual ~Level();
	virtual void onSourceCreated(BlockSource &);
	virtual void onSourceDestroyed(BlockSource &);
	virtual void onBlockChanged(BlockSource &, BlockPos const &, FullBlock, FullBlock, int);
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void addGlobalEntity(std::unique_ptr<Entity>);
	virtual void onPlayerDeath(Player &, EntityDamageSource const &);
	virtual void tick();
	virtual void directTickEntities(BlockSource &);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void runLightUpdates(BlockSource &, LightLayer const &, BlockPos const &, BlockPos const &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void onChunkLoaded(LevelChunk &);
	virtual void removeEntity(std::unique_ptr<Entity> &&, bool);
	virtual void removeEntity(Entity &, bool);
	virtual void onAppSuspended();
};
