#pragma once

#include "TileID.h"

class FullTile
{
public:
	static const FullTile AIR;

public:
	TileID id;
	unsigned char damage;
};