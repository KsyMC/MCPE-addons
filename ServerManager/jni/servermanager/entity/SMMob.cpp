#include "servermanager/entity/SMMob.h"
#include "minecraftpe/entity/Mob.h"

SMMob::SMMob(Server *server, Mob *entity)
	: SMEntity(server, entity)
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

bool SMMob::teleport(const Location &location, PlayerTeleportEvent::TeleportCause cause)
{
	if(getHealth() <= 0)
		return false;

	return SMEntity::teleport(location, cause);
}

float SMMob::getEyeHeight()
{
	return getHandle()->getHeadHeight();
}

float SMMob::getEyeHeight(bool ignoreSneaking)
{
	return getEyeHeight();
}

Mob *SMMob::getHandle() const
{
	return (Mob *)entity;
}

void SMMob::setHandle(Mob *entity)
{
	this->entity = entity;
}
