#include "servermanager/entity/SMCow.h"
#include "minecraftpe/entity/Cow.h"

SMCow::SMCow(Server *server, Cow *entity)
	: SMAnimal(server, entity)
{
}

Cow *SMCow::getHandle() const
{
	return (Cow *)entity;
}

void SMCow::setHandle(Cow *entity)
{
	this->entity = entity;
}
