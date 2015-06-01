#pragma once

#include "ScreenId.h"

class Screen;

class ScreenChooser
{
public:
	Screen *createScreen(ScreenId);
	void setScreen(ScreenId);
};