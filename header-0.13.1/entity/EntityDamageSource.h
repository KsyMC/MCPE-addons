#pragma once

#include "shared.h"
#include "minecraftpe/entity/EntityDamageCause.h"

class Entity;

class EntityDamageSource
{
public:
	//void **vtable;			// 0
	EntityDamageCause cause;	// 4

	EntityDamageSource(EntityDamageCause);
	virtual ~EntityDamageSource();
	virtual bool isEntitySource() const;
	virtual Entity *getEntity() const;
	virtual bool isChildEntitySource() const;
	virtual Entity *getChildEntity() const;
	virtual bool isBlockSource() const;
	virtual string getDeathMessage(string, Entity *) const;
	EntityDamageCause getCause() const;
};
