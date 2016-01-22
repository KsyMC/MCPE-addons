#pragma once

#include "minecraftpe/entity/Entity.h"

// Size : 392
class Arrow : public Entity
{
public:
	int xTile;		// 340
	int yTile;		// 344
	int zTile;		// 348
	bool onGround;		// 352
	char filler2[11];	// 353
	int shakeTime;		// 364
	bool fromPlayer;	// 368
	float baseDamage;	// 372
	int enchantPower;	// 376
	int enchantPunch;	// 380
	int enchantFlame;	// 384
	int enchantInfinity;	// 388

	virtual ~Arrow();
	virtual void lerpMotion(const Vec3 &);
	virtual void normalTick();
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius() const;
	virtual void playerTouch(Player &);
	virtual EntityType getEntityTypeId() const;
	virtual EntityUniqueID getSourceUniqueID();
	virtual void readAdditionalSaveData(const CompoundTag &);
	virtual void addAdditionalSaveData(CompoundTag &);
	int getEnchantInfinity() const;
};
