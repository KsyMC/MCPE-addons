#pragma once

#include "TileEntity.h"

class FunaceTileEntity : public TileEntity, public FillingContainer
{
public:
	FunaceTileEntity();
	virtual ~FunaceTileEntity();
};