#pragma once

#include "shared.h"

class Arrow;
class Player;

class CustomArrow
{
public:
	FUNCTION_HOOK_H(void, playerTouch, Arrow *, Player &);

	static void setupHooks();
};
