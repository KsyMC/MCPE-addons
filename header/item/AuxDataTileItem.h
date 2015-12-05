#pragma once

#include "TileItem.h"

class AuxDataTileItem : public TileItem
{
public:
	Block *tile;		// 76

public:
	AuxDataTileItem(int, Block *);
	virtual ~AuxDataTileItem();
	virtual int getLevelDataForAuxValue(int) const;
	virtual std::string getName(const ItemInstance *) const;
};
