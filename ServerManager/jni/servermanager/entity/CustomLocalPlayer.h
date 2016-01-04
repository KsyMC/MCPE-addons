#pragma once

#include "shared.h"
#include "minecraftpe/gamemode/GameType.h"
#include "minecraftpe/util/UUID.h"
#include "raknet/RakNetTypes.h"

class LocalPlayer;
class MinecraftClient;
class Level;
class User;

class CustomLocalPlayer
{
public:
	FUNCTION_HOOK_H(void, constructor, LocalPlayer *, MinecraftClient *, Level &, const User &, GameType, const RakNet::RakNetGUID &, mce::UUID);

	static void setupHooks();
};
