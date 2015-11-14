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
	virtual ~TileSourceListener();
	virtual void onSourceCreated(BlockSource *);
	virtual void onSourceDestroyed(BlockSource *);
	virtual void onTilesDirty(BlockSource *, int, int, int, int, int, int);
	virtual void onAreaChanged(BlockSource &, const BlockPos &, const BlockPos &);
	virtual void onTileChanged(BlockSource *, const BlockPos &, FullBlock, FullBlock, int);
	virtual void onBrightnessChanged(BlockSource &, const BlockPos &);
	virtual void onTileEntityChanged(BlockSource &, BlockEntity &);
	virtual void onTileEntityRemoved(BlockSource &, std::unique_ptr<BlockEntity> &);
	virtual void onTileEvent(BlockSource *, int, int, int, int, int);
};
