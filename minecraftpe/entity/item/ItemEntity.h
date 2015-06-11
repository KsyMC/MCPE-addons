#pragma once

#include "../Entity.h"

class ItemEntity : public Entity
{
public:
	static int LIFETIME;

public:
	ItemEntity(TileSource &);
	ItemEntity(TileSource &, float, float, float, const ItemInstance &);
	virtual ~ItemEntity();
	virtual void normalTick();
	virtual void playerTouch(Player *);
	virtual void isPushable();
	virtual void hurt(EntityDamageSource &, int);
	virtual void getEntityTypeId() const;
	virtual void isItemEntity();
	virtual void getHandleWaterAABB() const;
	virtual void burn(int);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	void _validateitem();
	bool checkInTile(float, float, float);
	float getLifeTime();
};
