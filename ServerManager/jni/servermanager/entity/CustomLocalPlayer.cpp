#include <dlfcn.h>

#include "servermanager/entity/CustomLocalPlayer.h"
#include "servermanager/ServerManager.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/entity/player/LocalPlayer.h"
#include "minecraftpe/level/Level.h"
#include "hook/Substrate.h"

FUNCTION_HOOK_CPP(void, CustomLocalPlayer, constructor, LocalPlayer *real, MinecraftClient *client, Level &level, const User &user, GameType gameType, const RakNet::RakNetGUID &guid, mce::UUID uuid)
{
	constructor_real(real, client, level, user, gameType, guid, uuid);

	if(!level.isClientSide())
		ServerManager::getServer()->start(real, &level);
}

void CustomLocalPlayer::setupHooks()
{
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN11LocalPlayerC2EP15MinecraftClientR5LevelRK4User8GameTypeRKN6RakNet10RakNetGUIDEN3mce4UUIDE"), (void **) &constructor, (void **) &constructor_real);
}
