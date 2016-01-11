#include <dlfcn.h>

#include "servermanager/level/custom/CustomLevel.h"
#include "servermanager/ServerManager.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomLevel, removeEntity, Level *real, Entity *entity, bool b)
{
	ServerManager::getServer()->removeEntity(entity);
	removeEntity_real(real, entity, b);
}

void CustomLevel::setupHooks()
{
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN5Level12removeEntityER6Entityb"), (void *)&removeEntity, (void **)&removeEntity_real);
}
