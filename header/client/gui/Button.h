#pragma once

#include "GuiElement.h"
#include "Color.h"

// Size : 108
class Button : public GuiElement
{
public:
	Color unclickedTextColor;		// 48
	Color clickedTextColor;			// 64
	Color shadowColor;				// 80
	std::string displayString;		// 96
	int id;							// 100
	bool toggled;					// 104
	bool pressed;					// 105
	bool overrideScreenRendering;	// 106

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
