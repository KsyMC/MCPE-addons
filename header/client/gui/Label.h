#pragma once

#include "Color.h"
#include "GuiElement.h"

// Size : 84
class Label : public GuiElement
{
public:
	std::string displayString;		// 48
	MinecraftClient* mc;			// 52
	Color textColor;				// 56
	int horzSideEdge;				// 72
	int vertSideEdge;				// 76
	bool isWidthLimited;			// 80
	bool hasShadow;					// 81
	bool isCentered;				// 82
	bool isPointerPressed;			// 83

public:
	Label(MinecraftClient &, std::string const &, Color const &, int, int, int, bool);
	virtual ~Label();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void pointerPressed(MinecraftClient *, int, int);
	virtual void pointerReleased(MinecraftClient *, int, int);
	virtual void getText() const;
	virtual void setText(std::string const &);
	virtual void setTextRaw(std::string const &);
	virtual void setWidth(int);
	virtual void setColor(Color const &);
	void setCentered(bool);
};
