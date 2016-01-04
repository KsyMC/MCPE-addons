#include "servermanager/entity/SMMob.h"
#include "minecraftpe/entity/Mob.h"

SMMob::SMMob(Mob *entity)
	: SMEntity(entity)
{
}

int SMMob::getHealth() const
{
	return getHandle()->getHealth();
}

void SMMob::setHealth(int health)
{
	getHandle()->serializationSetHealth(health);
}

int SMMob::getMaxHealth() const
{
	return getHandle()->getMaxHealth();
}

Mob *SMMob::getHandle() const
{
	return (Mob *)entity;
}
