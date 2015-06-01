#pragma once

#include "GuiElementContainer.h"

// Size : 148
class PackedScrollContainer : public GuiElementContainer
{
public:
	char filler1[20];	// 128

public:
	PackedScrollContainer(bool, int, int);
	virtual ~PackedScrollContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void setTextboxText(const std::string &);
};
