#pragma once

#include "TileEntity.h"

class ChestTileEntity : public TileEntity, public FillingContainer
{
public:
	ChestTileEntity();
	virtual ~ChestTileEntity();
};