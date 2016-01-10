#pragma once

#include <memory>
#include "FullBlock.h"
#include "BlockEntity.h"

class BlockSource;
class BlockPos;

class BlockSourceListener
{
public:
	virtual ~BlockSourceListener();
	virtual void onSourceCreated(BlockSource &);
	virtual void onSourceDestroyed(BlockSource &);
	virtual void onBlocksDirty(BlockSource &, int, int, int, int, int, int);
	virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void onBlockChanged(BlockSource &, BlockPos const &, FullBlock, FullBlock, int);
	virtual void onBrightnessChanged(BlockSource &, BlockPos const &);
	virtual void onBlockEntityChanged(BlockSource &, BlockEntity &);
	virtual void onBlockEntityRemoved(BlockSource &, std::unique_ptr<BlockEntity>);
	virtual void onBlockEvent(BlockSource &, int, int, int, int, int);
};
