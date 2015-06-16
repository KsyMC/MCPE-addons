#pragma once

#include "TileItem.h"

class AuxDataTileItem : public TileItem
{
public:
	Tile *tile;		// 76

public:
	AuxDataTileItem(int, Tile *);
	virtual ~AuxDataTileItem();
	virtual int getLevelDataForAuxValue(int) const;
	virtual std::string getName(const ItemInstance *) const;
};
