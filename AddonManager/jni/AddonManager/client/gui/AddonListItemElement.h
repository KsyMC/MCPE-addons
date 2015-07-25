#pragma once

#include <functional>
#include "minecraftpe/client/gui/GuiElement.h"

namespace Touch
{
	class TButton;
}

class Button;
class Addon;

class AddonListItemElement : public GuiElement
{
public:
	Touch::TButton *mainButton;
	Button *clickedButton;
	float clickedX;
	float clickedY;
	Addon *addon;
	std::function<void (Addon *)> f_setItem;

public:
	AddonListItemElement(MinecraftClient *, Addon *, std::function<void (Addon *)>);
	virtual ~AddonListItemElement();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
};
