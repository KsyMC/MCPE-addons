#pragma once

#include <memory>

#include "minecraftpe/entity/Entity.h"
#include "shared.h"

class Level;
class Entity;

class CustomLevel
{
public:
	FUNCTION_HOOK_H(void, removeEntity, Level *, Entity *, bool);

	static void setupHooks();
};
