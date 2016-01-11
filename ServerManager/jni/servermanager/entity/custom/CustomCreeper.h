#pragma once

#include "shared.h"

class Creeper;

class CustomCreeper
{
public:
	FUNCTION_HOOK_H(void, onLightningHit, Creeper *);

	static void setupHooks();
};
