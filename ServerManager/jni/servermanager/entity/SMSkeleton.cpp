#include "servermanager/entity/SMSkeleton.h"
#include "minecraftpe/entity/Skeleton.h"

SMSkeleton::SMSkeleton(Server *server, Skeleton *entity)
	: SMMob(server, entity)
{
}

Skeleton *SMSkeleton::getHandle() const
{
	return (Skeleton *)entity;
}

void SMSkeleton::setHandle(Skeleton *entity)
{
	this->entity = entity;
}
