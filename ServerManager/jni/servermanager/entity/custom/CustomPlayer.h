#pragma once

#include "shared.h"

class Player;
class ItemInstance;
class Entity;
class BlockPos;

class CustomPlayer
{
public:
	FUNCTION_HOOK_H(void, drop, Player *, ItemInstance *, bool);
	FUNCTION_HOOK_H(int, startSleepInBed, Player *, const BlockPos &);
	FUNCTION_HOOK_H(void, stopSleepInBed, Player *, bool, bool);

	static void setupHooks();
};
