#include "servermanager/entity/SMBlaze.h"
#include "minecraftpe/entity/Blaze.h"

SMBlaze::SMBlaze(Server *server, Blaze *entity)
	: SMMob(server, entity)
{
}

Blaze *SMBlaze::getHandle() const
{
	return (Blaze *)entity;
}

void SMBlaze::setHandle(Blaze *entity)
{
	this->entity = entity;
}
