#pragma once

#include "minecraftpe/level/BlockSourceListener.h"
#include "minecraftpe/client/AppPlatformListener.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/level/Difficulty.h"
#include "minecraftpe/block/FullBlock.h"
#include "minecraftpe/block/BlockPos.h"

class BlockSource;
class LocalPlayer;
class Dimension;
class LightLayer;
class LevelChunk;
class LevelStorage;
class EntityDamageSource;
class LevelData;

class Level : public BlockSourceListener, public AppPlatformListener
{
public:
	//void **vtable;					// 4
	char filler[4];						// 8
	vector<unique_ptr<Player>> players;	// 12

	virtual ~Level();
	virtual void onSourceCreated(BlockSource &);
	virtual void onSourceDestroyed(BlockSource &);
	virtual void onBlockChanged(BlockSource &, BlockPos const &, FullBlock, FullBlock, int);
	virtual void addEntity(unique_ptr<Entity>);
	virtual void addPlayer(unique_ptr<Player>);
	virtual void addGlobalEntity(unique_ptr<Entity>);
	virtual void onPlayerDeath(Player &, EntityDamageSource const &);
	virtual void tick();
	virtual void directTickEntities(BlockSource &);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void runLightUpdates(BlockSource &, LightLayer const &, BlockPos const &, BlockPos const &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void onChunkLoaded(LevelChunk &);
	virtual void removeEntity(unique_ptr<Entity> &&, bool);
	virtual void removeEntity(Entity &, bool);
	virtual void onAppSuspended();
	Player *getPlayer(string const &) const;
	LocalPlayer *getLocalPlayer() const;
	vector<unique_ptr<Player>> &getPlayers();
	Dimension *createDimension(DimensionId);
	LevelStorage *getLevelStorage();
	bool isClientSide() const;
	void setDayCycleActive(bool);
	void setTime(int);
	bool isDayCycleActive();
	int getTime() const;
	LevelData *getLevelData();
	BlockPos getDefaultSpawn() const;
};
