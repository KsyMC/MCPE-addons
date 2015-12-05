#pragma once

#include "EntityDamageSource.h"

class EntityDamageByEntitySource : public EntityDamageSource
{
public:
	virtual ~EntityDamageByEntitySource();
	virtual bool isEntitySource();
	virtual bool isTileSource();
	virtual std::string getDeathMessage(std::string, Entity *);
	virtual bool isChildEntitySource();
};