#pragma once

#include "TileEntity.h"

class MobSpawnerTileEntity : public TileEntity, public FillingContainer
{
public:
	MobSpawnerTileEntity();
	virtual ~MobSpawnerTileEntity();
};