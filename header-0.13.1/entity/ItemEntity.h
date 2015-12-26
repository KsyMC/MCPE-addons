#pragma once

#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/network/Packet.h"

class BlockSource;
class Vec3;
class ItemInstance;
class Player;
class EntityDamageSource;
class CompoundTag;

// Size : 384
class ItemEntity : public Entity
{
public:
	char filler1[264];	// 120

	ItemEntity(BlockSource &);
	ItemEntity(BlockSource &, Vec3 const &, ItemInstance const &, int);
	virtual ~ItemEntity();
	virtual unique_ptr<Packet> getAddPacket();
	virtual void normalTick();
	virtual void playerTouch(Player &);
	virtual bool isPushable() const;
	virtual void hurt(EntityDamageSource const &, int);
	virtual int getEntityTypeId() const;
	virtual EntityUniqueID getSourceUniqueID();
	virtual void getHandleWaterAABB() const;
	virtual void burn(int);
	virtual void readAdditionalSaveData(CompoundTag const &);
	virtual void addAdditionalSaveData(CompoundTag &);
	void setSourceEntity(Entity const *);
};
