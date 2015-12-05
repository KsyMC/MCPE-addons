#pragma once

#include "DiggerItem.h"

class PickaxeItem : public DiggerItem
{
public:
	PickaxeItem(int, const Item::Tier &);
	virtual ~PickaxeItem();
	virtual float getDestroySpeed(ItemInstance *, Block *);
	virtual bool canDestroySpecial(const Block *) const;
};
