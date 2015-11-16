#pragma once

#include "GuiElement.h"

// Size : 108
class Button : public GuiElement
{
public:
	char filler1[60];		// 48

public:
	Button(int, int, int, int, int, std::string const &, bool);
	Button(int, int, int, std::string const &);
	Button(int, std::string const &, bool);
	virtual ~Button();
	virtual void ~Button();
	virtual void render(MinecraftClient *, int, int);
	virtual void pointerReleased(MinecraftClient *, int, int);
	virtual void drawPressed(int);
	virtual void clicked(MinecraftClient *, int, int);
	virtual void released(int, int);
	virtual void setPressed();
	virtual void setPressed(bool);
	virtual void setMsg(std::string const &);
	virtual void getYImage(bool);
	virtual void renderBg(MinecraftClient *, int, int);
	virtual void renderFace(MinecraftClient *, int, int);
	int _getWidth(MinecraftClient *, std::string const &, int);
	bool hovered(MinecraftClient *, int, int);
	bool isInside(int, int);
	bool isOveridingScreenRendering();
	bool isPressed(int, int);
	void setOverrideScreenRendering(bool);
};
