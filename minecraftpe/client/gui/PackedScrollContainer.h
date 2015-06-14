#pragma once

#include "GuiElementContainer.h"

// Size : 140
class PackedScrollContainer : public GuiElementContainer
{
public:
	char filler1[12];	// 128

public:
	PackedScrollContainer(bool, bool);
	virtual ~PackedScrollContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void setTextboxText(const std::string &);
};
