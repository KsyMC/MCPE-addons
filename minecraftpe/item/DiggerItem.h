#pragma once

#include "Item.h"

class DiggerItem : public Item
{
public:
	virtual ~DiggerItem();
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual void getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual bool isHandEquipped() const;
};
