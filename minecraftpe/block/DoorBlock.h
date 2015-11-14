#pragma once

#include <minecraftpe/block/Block.h>

// Size : 268
class DoorBlock : public Block
{
public:
	TextureUVCoordinateSet texture1;	 // 140
	TextureUVCoordinateSet texture2;	 // 172
	TextureUVCoordinateSet texture3;	 // 204
	TextureUVCoordinateSet texture4;	 // 236

public:
	DoorBlock(int, const Material *);
	virtual ~DoorBlock();
	virtual AABB *getShape(TileSource *, int, int, int, AABB &, bool);
	virtual TextureUVCoordinateSet getTexture(signed char, int);
	virtual TextureUVCoordinateSet getTexture(TileSource *, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual bool mayPlace(TileSource *, int, int, int);
	virtual void playerWillDestroy(Player *, int, int, int, int);
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual TilePos *getSecondPart(TileSource &, const TilePos &, TilePos &);
	virtual int getResource(int, Random *);
	virtual void use(Player *, int, int, int);
	virtual void attack(Player *, int, int, int);
};
