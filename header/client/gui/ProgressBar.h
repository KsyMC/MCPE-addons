#pragma once

#include "GuiElementContainer.h"

// Size : 152
class ProgressBar : public GuiElementContainer
{
public:
	char filler1[24];		// 128

public:
	ProgressBar(MinecraftClient &, const Color &);
	virtual void tick(MinecraftClient *);
	void updateText();
};
