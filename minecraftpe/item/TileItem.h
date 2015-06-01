#pragma once

#include "Item.h"
#include "..\client\renderer\texture\TextureUVCoordinateSet.h"

// Size : 80
class TileItem : public Item
{
public:
	char filler1[4];	// 76

public:
	TileItem(int);
	virtual ~TileItem();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual float getIconYOffset() const;
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual std::string getName(const ItemInstance *) const;
	virtual bool isEmissive(int) const;
};