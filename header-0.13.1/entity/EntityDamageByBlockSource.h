#pragma once

#include "minecraftpe/entity/EntityDamageSource.h"
#include "minecraftpe/block/FullBlock.h"

class EntityDamageByBlockSource : public EntityDamageSource
{
public:
	FullBlock block;	// 8

	EntityDamageByBlockSource(FullBlock, EntityDamageCause);
	virtual ~EntityDamageByBlockSource();
	virtual bool isBlockSource() const;
	virtual string getDeathMessage(string, Entity *) const;
	FullBlock getBlock() const;
};
