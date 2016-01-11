#include "servermanager/entity/SMMonster.h"
#include "minecraftpe/entity/Monster.h"

SMMonster::SMMonster(Server *server, Monster *entity)
	: SMPathfinderMob(server, entity)
{
}

Monster *SMMonster::getHandle() const
{
	return (Monster *)entity;
}

void SMMonster::setHandle(Monster *entity)
{
	this->entity = entity;
}
