#pragma once

#include "GuiElement.h"

// Size : 168
class Button : public GuiElement
{
public:
	char filler1[48];				// 108
	std::string displayString;		// 156
	int id;							// 160
	bool toogled;					// 164
	bool pressed;					// 165
	bool overrideScreenRendering;	// 166

public:
	Button(int, int, int, int, int, const std::string &, bool);
	Button(int, int, int, const std::string &);
	Button(int, const std::string &, bool);
	virtual ~Button();
	virtual void render(MinecraftClient *, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual bool clicked(MinecraftClient *, int, int);
	virtual void released(int, int);
	virtual void setPressed();
	virtual void setMsg(const std::string &);
	virtual void getYImage(bool);
	virtual void renderBg(MinecraftClient *, int, int);
	virtual void renderFace(MinecraftClient *, int, int);
	int _getWidth(MinecraftClient *, const std::string &, int);
	bool hovered(MinecraftClient *, int, int);
	bool isInside(int, int);
	bool isOveridingScreenRendering();
	bool isPressed(int, int);
	void setOverrideScreenRendering(bool);
};
