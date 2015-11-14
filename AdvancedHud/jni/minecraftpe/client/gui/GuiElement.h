#pragma once

#include <string>
#include "GuiComponent.h"
#include "../../util/Color.h"

class StickDirection;
class MinecraftClient;
class NinePatchLayer;
class Vec2;

// Size : 108
class GuiElement : public GuiComponent
{
public:
	bool enabled;					// 64
	bool visible;					// 65
	int xPosition;					// 68
	int yPosition;					// 72
	int width;						// 76
	int height;						// 80
	Color color;					// 84
	NinePatchLayer *ninePatchLayer;	// 100
	bool selected;					// 104

public:
	GuiElement(bool, bool, int, int, int, int);
	virtual ~GuiElement();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void pointerPressed(MinecraftClient *, int, int);
	virtual void pointerReleased(MinecraftClient *, int, int);
	virtual void focusedMouseClicked(MinecraftClient *, int, int);
	virtual void focusedMouseReleased(MinecraftClient *, int, int);
	virtual void handleButtonPress(MinecraftClient *, short);
	virtual void handleButtonRelease(MinecraftClient *, short);
	virtual void handleTextChar(MinecraftClient *, std::string const &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void setKeyboardHeight(MinecraftClient *, float, Vec2 const &);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(std::string const &);
	virtual void hasFocus() const;
	virtual void setFocus(bool);
	virtual void handleControllerDirectionHeld(int, StickDirection);
	virtual void drawSelected(int);
	virtual void drawPressed(int);
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	virtual void hasChildren() const;
	void clearBackground();
	bool isSelected();
	void setBackground(const Color &);
	void setBackground(MinecraftClient *, const std::string &, const IntRectangle &, int, int);
	void setVisible(bool);
	void setSelected(bool);
	void setActiveAndVisibility(bool, bool);
	void setActiveAndVisibility(bool);
};
