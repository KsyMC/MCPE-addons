#pragma once

#include <memory>

class Mob;
class Player;
class Entity;
class LevelChunk;
class Vec3;
class BlockSource;
class BlockEntity;
class BlockPos;
class FullBlock;

class BlockSourceListener
{
public:
	//**void vtable;	// 0

public:
	virtual ~BlockSourceListener();
	virtual void onSourceCreated(BlockSource *);
	virtual void onSourceDestroyed(BlockSource *);
	virtual void onBlocksDirty(BlockSource *, int, int, int, int, int, int);
	virtual void onAreaChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void onBlockChanged(BlockSource *, BlockPos const &, FullBlock, FullBlock, int);
	virtual void onBrightnessChanged(BlockSource &, BlockPos const &);
	virtual void onBlockEntityChanged(BlockSource &, BlockEntity &);
	virtual void onBlockEntityRemoved(BlockSource &, std::unique_ptr<BlockEntity> &);
	virtual void onBlockEvent(BlockSource *, int, int, int, int, int);
};
