#pragma once

#include "Item.h"

// Size : 76
class HangingEntityItem : public Item
{
public:
	int entityTypeId;		// 72

public:
	HangingEntityItem(int, int);
	virtual ~HangingEntityItem();
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	void createEntity(TileSource &, int, int, int, int);
};
