#pragma once

#include "GuiElement.h"

// Size : 168
class Button : public GuiElement
{
public:
	char filler1[60];	// 108

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
	void setOverrideScreenRendering(bool);
	void isOveridingScreenRendering(void);
	bool isInside(int, int);
	bool hovered(MinecraftClient *, int, int);
};