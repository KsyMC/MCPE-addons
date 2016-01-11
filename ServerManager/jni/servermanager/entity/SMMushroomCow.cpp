#include "servermanager/entity/SMMushroomCow.h"
#include "minecraftpe/entity/Mushroomcow.h"

SMMushroomCow::SMMushroomCow(Server *server, MushroomCow *entity)
	: SMAnimal(server, entity)
{
}

MushroomCow *SMMushroomCow::getHandle() const
{
	return (MushroomCow *)entity;
}

void SMMushroomCow::setHandle(MushroomCow *entity)
{
	this->entity = entity;
}
