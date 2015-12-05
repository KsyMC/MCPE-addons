#pragma once

#include "Item.h"

// Size : 80
class TileItem : public Item
{
public:
	bool tileId;		// 76

public:
	TileItem(int);
	virtual ~TileItem();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual std::string getName(const ItemInstance *) const;
	virtual bool isEmissive(int) const;
};
