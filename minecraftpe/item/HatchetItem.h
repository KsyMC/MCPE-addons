#pragma once

#include "DiggerItem.h"

class HatchetItem : public DiggerItem
{
public:
	HatchetItem(int, const Item::Tier &);
	virtual ~HatchetItem();
	virtual void getDestroySpeed(ItemInstance *, Tile *);
};
