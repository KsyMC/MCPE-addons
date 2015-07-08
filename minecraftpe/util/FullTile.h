#pragma once

#include "TileID.h"

class FullTile
{
public:
	static FullTile AIR;

public:
	TileID tileID;
	unsigned char damage;

public:
	FullTile() : tileID(0), damage(0) {};
	FullTile(TileID tileId, unsigned char damage) : tileID(tileId), damage(damage) {}
};
