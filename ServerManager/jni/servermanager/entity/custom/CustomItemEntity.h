#pragma once

#include "shared.h"

class ItemEntity;
class Player;

class CustomItemEntity
{
public:
	FUNCTION_HOOK_H(void, playerTouch, ItemEntity *, Player &);

	static void setupHooks();
};
