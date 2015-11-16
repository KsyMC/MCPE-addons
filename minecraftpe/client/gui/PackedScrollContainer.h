#pragma once

#include "GuiElementContainer.h"

class ScrollingPane;

// Size : 112
class PackedScrollContainer : public GuiElementContainer
{
public:
	char filler1[44];		// 68

public:
	PackedScrollContainer(bool, bool);
	virtual ~PackedScrollContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void pointerPressed(MinecraftClient *, int, int);
	virtual void setTextboxText(std::string const &);
};
