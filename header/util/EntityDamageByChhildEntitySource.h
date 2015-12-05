#pragma once

#include "EntityDamageByEntitySource.h"

class EntityDamageByChhildEntitySource : public EntityDamageByEntitySource
{
public:
	virtual ~EntityDamageByChhildEntitySource();
	virtual bool isEntitySource();
	virtual bool isTileSource();
	virtual std::string getDeathMessage(std::string, Entity *);
	virtual bool isChildEntitySource();
};