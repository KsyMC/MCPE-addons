#pragma once

#include "Item.h"

class WeaponItem : public Item
{
public:
	virtual ~WeaponItem();
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual int getMaxUseDuration() const;
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual void getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual void isHandEquipped() const;
};
