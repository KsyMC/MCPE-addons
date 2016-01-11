#include "servermanager/entity/SMArrow.h"
#include "minecraftpe/entity/Arrow.h"

SMArrow::SMArrow(Server *server, Arrow *entity)
	: SMEntity(server, entity)
{
}

Arrow *SMArrow::getHandle() const
{
	return (Arrow *)entity;
}

void SMArrow::setHandle(Arrow *entity)
{
	this->entity = entity;
}
