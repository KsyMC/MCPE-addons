#pragma once

#include "minecraftpe/client/gui/GuiElement.h"

namespace Touch
{
	class TButton;
}

class ImageWithBackground;
class Button;

class TestListItemElement : public GuiElement
{
public:
	Touch::TButton *mainButton;
	ImageWithBackground *removeButton;
	Button *clickedButton;
	int clickedX;
	int clickedY;

public:
	TestListItemElement(MinecraftClient *mc);
	virtual ~TestListItemElement();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
};
