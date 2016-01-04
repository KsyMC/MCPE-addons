#pragma once

#include "servermanager/entity/SMEntity.h"

class Mob;

class SMMob : public SMEntity
{
public:
	SMMob(Mob *entity);

	int getHealth() const;
	void setHealth(int);

	int getMaxHealth() const;

	Mob *getHandle() const;
};
