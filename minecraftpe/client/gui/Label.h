#pragma once

#include "GuiElement.h"

// Size : 144
class Label : public GuiElement
{
public:
	char filler1[36];	// 108

public:
	Label(MinecraftClient *, std::string, const Color &, int, int, int, bool);
	virtual ~Label();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual std::string getText() const;
	virtual void setText(std::string);
	virtual void setTextRaw(const std::string &);
	virtual void setWidth(int);
	virtual void setColor(const Color &);
	void setCentered(bool);
};