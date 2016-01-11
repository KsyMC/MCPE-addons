#include "servermanager/entity/SMChicken.h"
#include "minecraftpe/entity/Chicken.h"

SMChicken::SMChicken(Server *server, Chicken *entity)
	: SMAnimal(server, entity)
{
}

Chicken *SMChicken::getHandle() const
{
	return (Chicken *)entity;
}

void SMChicken::setHandle(Chicken *entity)
{
	this->entity = entity;
}
