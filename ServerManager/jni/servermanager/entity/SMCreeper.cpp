#include "servermanager/entity/SMCreeper.h"
#include "servermanager/Server.h"
#include "servermanager/event/entity/CreeperPowerEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "minecraftpe/entity/Creeper.h"

SMCreeper::SMCreeper(Server *server, Creeper *entity)
	: SMMob(server, entity)
{
}

bool SMCreeper::isPowered() const
{
	return getHandle()->isPowered();
}

void SMCreeper::setPowered(bool powered)
{
	CreeperPowerEvent event(this, powered ? CreeperPowerEvent::SET_ON : CreeperPowerEvent::SET_OFF);
	server->getPluginManager()->callEvent(event);

	if(!event.isCancelled())
		getHandle()->_setPowered(powered);
}

Creeper *SMCreeper::getHandle() const
{
	return (Creeper *)entity;
}

void SMCreeper::setHandle(Creeper *entity)
{
	this->entity = entity;
}
