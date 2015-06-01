#pragma once

#include "Tile.h"

class TileEntity;

// Size : 140
class EntityTile : public Tile
{
public:
	EntityTile(int, const Material *);
	EntityTile(int, const std::string &, const Material *);
	virtual ~EntityTile();
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void triggerEvent(TileSource *, int, int, int, int, int);
	virtual TileEntity *newTileEntity(const TilePos &);
};