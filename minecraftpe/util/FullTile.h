#pragma once

#include "TileID.h"

class FullTile
{
public:
	static FullTile AIR;

public:
	TileID id;
	unsigned char damage;
};
