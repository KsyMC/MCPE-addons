#pragma once

#include <string>

class Entity;

class EntityDamageSource
{
public:
	virtual ~EntityDamageSource();
	virtual bool isEntitySource();
	virtual bool isTileSource();
	virtual std::string getDeathMessage(std::string, Entity *);
};