#pragma once

#include "Block.h"

// Size : 268
class DoorBlock : public Block
{
public:
	enum DoorType
	{

	};

public:
	TextureUVCoordinateSet texture1;	 // 140
	TextureUVCoordinateSet texture2;	 // 172
	TextureUVCoordinateSet texture3;	 // 204
	TextureUVCoordinateSet texture4;	 // 236

public:
	DoorBlock(std::string const &, int, Material const &, DoorType);
	virtual void ~DoorBlock();
	virtual void tick(BlockSource &, BlockPos const &, Random &);
	virtual void getVisualShape(BlockSource &, BlockPos const &, AABB &, bool);
	virtual void getTexture(signed char, int);
	virtual void getTexture(BlockSource &, BlockPos const &, signed char);
	virtual void getTessellatedUVs();
	virtual void isInteractiveBlock() const;
	virtual void isWaterBlocking() const;
	virtual void isDoorBlock() const;
	virtual void onPlace(BlockSource &, BlockPos const &);
	virtual void onRedstoneUpdate(BlockSource &, BlockPos const &, int, bool);
	virtual void onLoaded(BlockSource &, BlockPos const &);
	virtual void mayPlace(BlockSource &, BlockPos const &);
	virtual void playerWillDestroy(Player &, BlockPos const &, int);
	virtual void neighborChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void getSecondPart(BlockSource &, BlockPos const &, BlockPos &);
	virtual void getResource(Random &, int, int);
	virtual void asItemInstance(BlockSource &, BlockPos const &, int) const;
	virtual void use(Player &, BlockPos const &);
	virtual void canBeSilkTouched() const;
	virtual void getSilkTouchItemInstance(unsigned char);
};
