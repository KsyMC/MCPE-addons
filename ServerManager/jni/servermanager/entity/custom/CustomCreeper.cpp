#include "servermanager/entity/custom/CustomCreeper.h"
#include "servermanager/ServerManager.h"
#include "servermanager/event/entity/CreeperPowerEvent.h"
#include "servermanager/plugin/PluginManager.h"
#include "minecraftpe/entity/Creeper.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomCreeper, onLightningHit, Creeper *real)
{
	if(!real->level->isClientSide())
	{
		CreeperPowerEvent event((SMCreeper *)ServerManager::getEntity(real), CreeperPowerEvent::LIGHTNING);
		ServerManager::getPluginManager()->callEvent(event);

		if(event.isCancelled())
			return;
	}
	real->_setPowered(true);
}

void CustomCreeper::setupHooks()
{
	MSHookFunction((void *)&Creeper::onLightningHit, (void *)&onLightningHit, (void **)&onLightningHit_real);
}
