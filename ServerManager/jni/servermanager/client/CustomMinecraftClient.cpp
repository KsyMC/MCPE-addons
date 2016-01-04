#include <dlfcn.h>

#include "servermanager/client/CustomMinecraftClient.h"
#include "servermanager/ServerManager.h"
#include "minecraftpe/client/AppPlatform.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomMinecraftClient, init, MinecraftClient *client)
{
	init_real(client);
	ServerManager::getServer()->init(client->getServer(), AppPlatform::mSingleton->getUserdataPath() + client->dataDir);
}

FUNCTION_HOOK_CPP(void, CustomMinecraftClient, leaveGame, MinecraftClient *client, bool b1)
{
	ServerManager::getServer()->stop();
	leaveGame_real(client, b1);
}

FUNCTION_HOOK_CPP(void, CustomMinecraftClient, destructor, MinecraftClient *client)
{
	delete ServerManager::getServer();
	destructor_real(client);
}

void CustomMinecraftClient::setupHooks()
{
	MSHookFunction((void *) &MinecraftClient::init, (void **) &init, (void **) &init_real);
	MSHookFunction((void *) &MinecraftClient::leaveGame, (void **) &leaveGame, (void **) &leaveGame_real);
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClientD2Ev"), (void **) &destructor, (void **) &destructor_real);
}
