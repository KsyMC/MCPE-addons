#pragma once

#include "EntityDamageSource.h"

class EntityDamageByTileSource : public EntityDamageSource
{
public:
	virtual ~EntityDamageByTileSource();
	virtual bool isEntitySource();
	virtual bool isTileSource();
	virtual std::string getDeathMessage(std::string, Entity *);
};