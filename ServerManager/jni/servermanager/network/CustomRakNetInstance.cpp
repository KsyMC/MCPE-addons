#include "servermanager/network/CustomRakNetInstance.h"
#include "servermanager/ServerManager.h"
#include "minecraftpe/network/RakNetInstance.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomRakNetInstance, _startupIfNeeded, RakNetInstance *real, unsigned short port, int connections)
{
	_startupIfNeeded_real(real, ServerManager::getServer()->getPort(), ServerManager::getMaxPlayers());
}

FUNCTION_HOOK_CPP(void, CustomRakNetInstance, host, RakNetInstance *real, const std::string &name, int port, int connections)
{
	host_real(real, name, ServerManager::getPort(), ServerManager::getMaxPlayers());
}

void CustomRakNetInstance::setupHooks()
{
	MSHookFunction((void *) &RakNetInstance::_startupIfNeeded, (void **) &_startupIfNeeded, (void **) &_startupIfNeeded_real);
	MSHookFunction((void *) &RakNetInstance::host, (void **) &host, (void **) &host_real);
}
