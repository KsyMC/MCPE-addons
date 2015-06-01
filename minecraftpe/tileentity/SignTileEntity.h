#pragma once

#include "TileEntity.h"

class SignTileEntity : public TileEntity, public FillingContainer
{
public:
	SignTileEntity();
	virtual ~SignTileEntity();
};