#pragma once

#include "shared.h"
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
	virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void onBlockChanged(BlockSource &, BlockPos const &, FullBlock, FullBlock, int);
	virtual void onBrightnessChanged(BlockSource &, BlockPos const &);
	virtual void onBlockEntityChanged(BlockSource &, BlockEntity &);
	virtual void onBlockEntityRemoved(BlockSource &, unique_ptr<BlockEntity>);
	virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
};
