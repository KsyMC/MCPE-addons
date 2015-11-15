#pragma once

#include "Block.h"

class Color;

// Size : 140
class HeavyBlock : public Block
{
public:
	HeavyBlock(std::string const &, int, std::string const &, Material const &);
	virtual ~HeavyBlock();
	virtual void tick(BlockSource &, BlockPos const &, Random &);
	virtual void animateTick(BlockSource &, BlockPos const &, Random &);
	virtual void onPlace(BlockSource &, BlockPos const &);
	virtual void neighborChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual Color *getDustColor() const = 0;
	virtual void falling();
	virtual void onLand(BlockSource &, BlockPos const &);
	virtual void isFree(BlockSource &, BlockPos const &);
	virtual void startFalling(BlockSource &, BlockPos const &, Block *, bool);
	void _checkSlide(BlockSource *, int, int, int);
	void _findBottomSlidingTile(BlockSource &, const BlockPos &);
	void _isFree(BlockSource *, const BlockPos &);
	void _scheduleCheck(BlockSource &, const BlockPos &, Block *, int);
	void _scheduleCheckIfSliding(BlockSource &, const BlockPos &, Block *);
	void _startFalling(BlockSource &, const BlockPos &, Block *);
	void _tickTilesAround2D(BlockSource &, const BlockPos &, Block *);
};
