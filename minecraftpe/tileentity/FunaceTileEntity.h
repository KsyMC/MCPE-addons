#pragma once

#include "minecraftpe/tileentity/TileEntity.h"
#include "minecraftpe/inventory/FillingContainer.h"

class FunaceTileEntity : public TileEntity, public FillingContainer {
public:
	FunaceTileEntity();
	virtual ~FunaceTileEntity();
};
