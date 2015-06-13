#pragma once

#include "DiggerItem.h"

class PickaxeItem : public DiggerItem
{
public:
	PickaxeItem(int, const Item::Tier &);
	virtual ~PickaxeItem();
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
};
