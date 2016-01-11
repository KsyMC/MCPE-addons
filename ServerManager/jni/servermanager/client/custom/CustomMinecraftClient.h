#pragma once

#include "shared.h"

class MinecraftClient;

class CustomMinecraftClient
{
public:
	FUNCTION_HOOK_H(void, init, MinecraftClient *);
	FUNCTION_HOOK_H(void, leaveGame, MinecraftClient *, bool);
	FUNCTION_HOOK_H(void, destructor, MinecraftClient *);

	static void setupHooks();
};
