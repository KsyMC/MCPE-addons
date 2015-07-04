#pragma once

#include "GuiElementContainer.h"

class ScrollingPane;

// Size : 140
class PackedScrollContainer : public GuiElementContainer
{
public:
	ScrollingPane *pane;	// 128
	char filler1[8];		// 132

public:
	PackedScrollContainer(bool, bool);
	virtual ~PackedScrollContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void setTextboxText(const std::string &);
};
