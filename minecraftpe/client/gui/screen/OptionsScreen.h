#pragma once

#include <vector>

class MinecraftClient;
class OptionsPane;

class OptionsScreen
{
public:
	char filler1[20];				// 0
	MinecraftClient *client;		// 20
	char filler2[140];				// 24
	std::vector<std::shared_ptr<OptionsPane>> vectorPanes;	// 164

public:
	OptionsScreen();
	void _generateOptionScreensDefault();
};
