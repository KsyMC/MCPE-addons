#include "servermanager/entity/SMPig.h"
#include "minecraftpe/entity/Pig.h"

SMPig::SMPig(Server *server, Pig *entity)
	: SMAnimal(server, entity)
{
}

Pig *SMPig::getHandle() const
{
	return (Pig *)entity;
}

void SMPig::setHandle(Pig *entity)
{
	this->entity = entity;
}
