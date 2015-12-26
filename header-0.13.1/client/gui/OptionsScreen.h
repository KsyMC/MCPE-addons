#pragma once

#include "minecraftpe/client/gui/OptionsPane.h"

class MinecraftClient;

// Size : 288
class OptionsScreen
{
public:
	char filler1[20];						// 0
	MinecraftClient *client;				// 20
	char filler2[140];						// 24
	vector<shared_ptr<OptionsPane>> panes;	// 164

	void _generateOptionScreensDefault();
};
