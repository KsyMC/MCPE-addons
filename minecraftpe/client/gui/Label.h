#pragma once

#include "GuiElement.h"

// Size : 144
class Label : public GuiElement
{
public:
	std::string displayString;	// 108
	char filler1[4];			// 112
	Color color;				// 116
	char filler2[10];			// 132
	bool centered;				// 142

public:
	Label(MinecraftClient &, const std::string &, const Color &, int, int, int, bool);
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
