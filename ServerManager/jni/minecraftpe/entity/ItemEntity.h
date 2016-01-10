#pragma once

#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"

class BlockSource;
class Vec3;
class Player;
class EntityDamageSource;
class CompoundTag;

// Size : 384
class ItemEntity : public Entity
{
public:
	ItemInstance item;	// 340
	char filler2[8];	// 360
	int pickupDelay;	// 368
	char filler3[12];	// 372

	ItemEntity(BlockSource &);
	ItemEntity(BlockSource &, const Vec3 &, const ItemInstance &, int);
	virtual ~ItemEntity();
	virtual std::unique_ptr<Packet> getAddPacket();
	virtual void normalTick();
	virtual void playerTouch(Player &);
	virtual bool isPushable() const;
	virtual void hurt(const EntityDamageSource &, int);
	virtual EntityType getEntityTypeId() const;
	virtual EntityUniqueID getSourceUniqueID();
	virtual void getHandleWaterAABB() const;
	virtual void burn(int);
	virtual void readAdditionalSaveData(const CompoundTag &);
	virtual void addAdditionalSaveData(CompoundTag &);
	void setSourceEntity(const Entity *);
};
