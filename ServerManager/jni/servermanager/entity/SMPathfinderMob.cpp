#include "servermanager/entity/SMPathfinderMob.h"
#include "minecraftpe/entity/PathfinderMob.h"

SMPathfinderMob::SMPathfinderMob(Server *server, PathfinderMob *entity)
	: SMMob(server, entity)
{
}

PathfinderMob *SMPathfinderMob::getHandle() const
{
	return (PathfinderMob *)entity;
}

void SMPathfinderMob::setHandle(PathfinderMob *entity)
{
	this->entity = entity;
}
