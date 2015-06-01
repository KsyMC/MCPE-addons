#pragma once

#include "TileEntityType.h"

class TileEntity;
class TilePos;

class TileEntityFactory
{
public:
	static TileEntity *createTileEntity(TileEntityType, const TilePos &);
};