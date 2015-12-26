#pragma once

#include "minecraftpe/client/gui/GuiComponent.h"
#include "minecraftpe/StickDirection.h"

class MinecraftClient;
class Vec2;

// Size : 48
class GuiElement : public GuiComponent
{
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
	virtual void handleTextChar(MinecraftClient *, string const &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void setKeyboardHeight(MinecraftClient *, float, Vec2 const &);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(string const &);
	virtual void hasFocus() const;
	virtual void setFocus(bool);
	virtual void handleControllerDirectionHeld(int, StickDirection);
	virtual void drawSelected(int);
	virtual void drawPressed(int);
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	virtual void hasChildren() const;
};
