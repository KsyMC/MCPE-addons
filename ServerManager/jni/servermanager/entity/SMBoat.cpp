#include "servermanager/entity/SMBoat.h"
#include "minecraftpe/entity/Boat.h"

SMBoat::SMBoat(Server *server, Boat *entity)
	: SMEntity(server, entity)
{
}

Boat *SMBoat::getHandle() const
{
	return (Boat *)entity;
}

void SMBoat::setHandle(Boat *entity)
{
	this->entity = entity;
}
