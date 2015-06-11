#pragma once

#include "../Entity.h"

class Mob;

class Arrow : public Entity
{
public:
	static float ARROW_BASE_DAMAGE;

public:
	Arrow(Mob *, Mob *, float, float);
	Arrow(Mob *, float);
	Arrow(TileSource &);
	Arrow(TileSource &, float, float, float);
	virtual void lerpMotion(float, float, float);
	virtual void normalTick();
	virtual float getShadowRadius() const;
	virtual float getShadowHeightOffs();
	virtual void playerTouch(Player *);
	virtual int getEntityTypeId() const;
	virtual int getOwnerID();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	void _init();
	void shoot(float, float, float, float, float);
};
