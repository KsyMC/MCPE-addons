#pragma once

#include "minecraftpe/entity/Entity.h"

// Size : 392
class Arrow : public Entity
{
public:
	char filler1[12];	// 340
	bool onGround;		// 352
	char filler2[11];	// 353
	int shakeTime;		// 364
	bool fromPlayer;	// 368

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
