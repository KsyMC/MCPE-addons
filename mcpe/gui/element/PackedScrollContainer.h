#ifndef __PACKEDSCROLLCONTAINER_H__
#define __PACKEDSCROLLCONTAINER_H__

#include "GuiElementContainer.h"

class MinecraftClient;

class PackedScrollContainer : public GuiElementContainer {
public:
	// Size : 148
	char filler1[20];		// 128

public:
	PackedScrollContainer(bool, int, int);
	virtual ~PackedScrollContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked();
	virtual void setTextboxText(const std::string &);
};

#endif
