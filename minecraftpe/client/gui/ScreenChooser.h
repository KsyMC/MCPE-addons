#pragma once

#include "ScreenId.h"

class Screen;

// Size : 4
class ScreenChooser
{
public:
	MinecraftClient *mc;

public:
	Screen *createScreen(ScreenId);
	void setScreen(ScreenId);
};
