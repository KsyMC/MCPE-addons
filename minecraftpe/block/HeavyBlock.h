#pragma once

#include <minecraftpe/block/Block.h>

class Color;

// Size : 140
class HeavyTile : public Block
{
public:
	HeavyTile(int, const std::string &, const Material *);
	virtual ~HeavyTile();
	virtual void getTickDelay();
	virtual void tick(BlockSource *, int, int, int, Random *);
	virtual void animateTick(BlockSource *, int, int, int, Random *);
	virtual void neighborChanged(BlockSource *, int, int, int, int, int, int);
	virtual void onPlace(BlockSource *, int, int, int);
	virtual Color *getDustColor() = 0;
	void _checkSlide(BlockSource *, int, int, int);
	void _findBottomSlidingTile(BlockSource &, const BlockPos &);
	void _isFree(BlockSource *, const BlockPos &);
	void _scheduleCheck(BlockSource &, const BlockPos &, Block *, int);
	void _scheduleCheckIfSliding(BlockSource &, const BlockPos &, Block *);
	void _startFalling(BlockSource &, const BlockPos &, Block *);
	void _tickTilesAround2D(BlockSource &, const BlockPos &, Block *);
};
