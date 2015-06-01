#pragma once

#include "Tile.h"

// Size : 268
class DoorTile : public Tile
{
public:
	char filler1[128]; // 140

public:
	DoorTile(int, const Material *);
	virtual ~DoorTile();
	virtual AABB *getShape(TileSource *, int, int, int, AABB &, bool);
	virtual TextureUVCoordinateSet *getTexture(signed char, int);
	virtual TextureUVCoordinateSet *getTexture(TileSource *, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual bool mayPlace(TileSource *, int, int, int);
	virtual void playerWillDestroy(Player *, int, int, int, int);
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void getSecondPart(TileSource &, const TilePos &, TilePos &);
	virtual int getResource(int, Random *);
	virtual void use(Player *, int, int, int);
	virtual void attack(Player *, int, int, int);
};