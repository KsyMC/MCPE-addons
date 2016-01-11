#include "servermanager/entity/SMItemEntity.h"
#include "minecraftpe/entity/ItemEntity.h"

SMItemEntity::SMItemEntity(Server *server, ItemEntity *entity)
	: SMEntity(server, entity)
{
}

ItemEntity *SMItemEntity::getHandle() const
{
	return (ItemEntity *)entity;
}

void SMItemEntity::setHandle(ItemEntity *entity)
{
	this->entity = entity;
}
