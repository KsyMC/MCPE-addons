#pragma once

#include "minecraftpe/level/LevelListener.h"
#include "minecraftpe/SavedData.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/dimension/DimensionId.h"
#include "minecraftpe/block/FullBlock.h"
#include "minecraftpe/util/Color.h"

class BlockSource;
class BlockPos;
class Player;
class LevelChunk;
class CompoundTag;
class Packet;
class MoveEntityPacketData;
class Entity;
class ChunkSource;

// Size : 180
class Dimension : public LevelListener, public SavedData
{
public:
	//void **vtable;	// 0
	//void **vtable;	// 4
	char filler[172];	// 8

	Dimension(Level &, DimensionId);
	virtual ~Dimension();
	virtual void onBlockChanged(BlockSource &, const BlockPos &, FullBlock, FullBlock, int);
	virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void init();
	virtual void tick();
	virtual void updateLightRamp();
	virtual bool isNaturalDimension() const;
	virtual bool isValidSpawn(int, int) const;
	virtual Color getFogColor(float) const;
	virtual float getFogDistanceScale() const;
	virtual void isFoggyAt(int, int) const;
	virtual void getCloudHeight() const;
	virtual void mayRespawn() const;
	virtual void hasGround() const;
	virtual void getSpawnYPosition();
	virtual void hasBedrockFog();
	virtual void getClearColorScale();
	virtual std::string getName() const = 0;
	virtual void load(const CompoundTag &);
	virtual void save(CompoundTag &);
	virtual void sendDimensionPackets();
	virtual void sendBroadcast(const Packet &, Player *);
	virtual void addMoveEntityPacket(const MoveEntityPacketData &);
	virtual void addSetEntityMotionPacket(Entity &);
	virtual void getTimeOfDay(int, float) const;
	ChunkSource *getChunkSource() const;

	static std::unique_ptr<Dimension> createNew(DimensionId id, Level &level);

	bool isDay() const;

	void setCeiling(bool ceiling);
	void setUltraWarm(bool ultraWarm);
};
