#pragma once

#include <string>

class MinecraftClient;

class ChatScreen
{
public:
	char filler1[20];		// 0
	MinecraftClient *mc;	// 20
	char filler2[136];		// 24
	std::string message;	// 160

	void sendChatMessage();
};
