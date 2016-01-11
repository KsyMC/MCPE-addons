#pragma once

#include "minecraftpe/blockentity/BlockEntityType.h"

class CompoundTag;
class BlockSource;
class BlockPos;

class BlockEntity
{
public:
	BlockEntity(BlockEntityType, const BlockPos &, const std::string &);
	virtual ~BlockEntity();
	virtual void load(CompoundTag &);
	virtual void save(CompoundTag &);
	virtual void tick(BlockSource &);
	virtual void isFinished();
	virtual void onChanged(BlockSource &);
	virtual void getUpdatePacket(BlockSource &);
	virtual void onUpdatePacket(CompoundTag &);
	virtual void onRemoved();
	virtual void triggerEvent(int, int);
	virtual void clearCache();
	virtual void onNeighborChanged(BlockSource &, int, int, int);
	virtual void onNeighborChanged(BlockSource &, const BlockPos &);
	virtual void getShadowRadius(BlockSource &) const;
	virtual void getCrackEntity(BlockSource &, const BlockPos &);
	static bool isType(BlockEntity &, BlockEntityType);
};
