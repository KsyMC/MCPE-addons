#pragma once

#include "minecraftpe/entity/EntityDamageSource.h"

class EntityDamageByEntitySource : public EntityDamageSource
{
public:
	Entity *damager;		// 8

	EntityDamageByEntitySource(Entity &, EntityDamageCause);
	virtual ~EntityDamageByEntitySource();
	virtual bool isEntitySource() const;
	virtual Entity *getEntity() const;
	virtual string getDeathMessage(string, Entity *) const;
};
