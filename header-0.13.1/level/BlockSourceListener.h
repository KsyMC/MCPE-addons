#pragma once

#include <memory>

#include "minecraftpe/block/FullBlock.h"
#include "minecraftpe/entity/BlockEntity.h"

class BlockSource;
class BlockPos;

class BlockSourceListener
{
public:
	//void **vtable;	// 0

	virtual ~BlockSourceListener();
	virtual void onSourceCreated(BlockSource &);
	virtual void onSourceDestroyed(BlockSource &);
	virtual void onBlocksDirty(BlockSource &, int, int, int, int, int, int);
	virtual void onAreaChanged(BlockSource &, const BlockPos &, const BlockPos &);
	virtual void onBlockChanged(BlockSource &, const BlockPos &, FullBlock, FullBlock, int);
	virtual void onBrightnessChanged(BlockSource &, const BlockPos &);
	virtual void onBlockEntityChanged(BlockSource &, BlockEntity &);
	virtual void onBlockEntityRemoved(BlockSource &, std::unique_ptr<BlockEntity>);
	virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
};
