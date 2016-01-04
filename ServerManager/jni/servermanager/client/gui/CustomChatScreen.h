#pragma once

#include "shared.h"

class ChatScreen;

class CustomChatScreen
{
public:
	FUNCTION_HOOK_H(void, sendChatMessage, ChatScreen *);

	static void setupHooks();
};
