#pragma once

#include "minecraftpe/entity/EntityDamageSource.h"

class RemovedEntityDamageByType : public EntityDamageSource
{
public:
	RemovedEntityDamageByType(EntityDamageCause, EntityType);
	virtual ~RemovedEntityDamageByType();
	virtual string getDeathMessage(string, Entity *) const;
};
