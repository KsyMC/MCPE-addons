#pragma once

#include <string>

#include "shared.h"

class RakNetInstance;

class CustomRakNetInstance
{
public:
	FUNCTION_HOOK_H(void, _startupIfNeeded, RakNetInstance *, unsigned short port, int connections);
	FUNCTION_HOOK_H(void, host, RakNetInstance *, const std::string &name, int port, int connections);

	static void setupHooks();
};
