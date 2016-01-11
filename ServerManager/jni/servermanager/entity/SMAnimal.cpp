#include "servermanager/entity/SMAnimal.h"
#include "minecraftpe/entity/Animal.h"

SMAnimal::SMAnimal(Server *server, Animal *entity)
	: SMAgableMob(server, entity)
{
}

Animal *SMAnimal::getHandle() const
{
	return (Animal *)entity;
}

void SMAnimal::setHandle(Animal *entity)
{
	this->entity = entity;
}
