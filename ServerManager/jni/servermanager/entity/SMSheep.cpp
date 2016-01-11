#include "servermanager/entity/SMSheep.h"
#include "minecraftpe/entity/Sheep.h"

SMSheep::SMSheep(Server *server, Sheep *entity)
	: SMAnimal(server, entity)
{
}

Sheep *SMSheep::getHandle() const
{
	return (Sheep *)entity;
}

void SMSheep::setHandle(Sheep *entity)
{
	this->entity = entity;
}
