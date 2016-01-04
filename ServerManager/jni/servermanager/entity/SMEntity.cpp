#include "servermanager/entity/SMEntity.h"
#include "minecraftpe/entity/Entity.h"

SMEntity::SMEntity(Entity *entity)
{
	this->entity = entity;
}

SMEntity::~SMEntity()
{
}

int SMEntity::getEntityId() const
{
	return entity->getEntityTypeId();
}

bool SMEntity::isDead() const
{
	return entity->isAlive();
}

EntityUniqueID SMEntity::getUniqueId() const
{
	return entity->getUniqueID();
}

void SMEntity::setNameTag(const std::string &name)
{
	entity->setNameTag(name);
}

std::string SMEntity::getNameTag() const
{
	return entity->getNameTag();
}

void SMEntity::setNameTagVisible(bool flag)
{
	entity->setNameTagVisible(flag);
}

bool SMEntity::isNameTagVisible()
{
	return entity->canShowNameTag();
}

Entity *SMEntity::getHandle() const
{
	return entity;
}
