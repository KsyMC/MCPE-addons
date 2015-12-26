#pragma once

#include "minecraftpe/client/gui/GuiElement.h"

// Size : 68
class GuiElementContainer : public GuiElement
{
public:
	GuiElementContainer(bool, bool, int, int, int, int);
	virtual ~GuiElementContainer();
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
	virtual void suppressOtherGUI();
	virtual void setTextboxText(string const &);
	virtual void hasChildren() const;
	virtual void addChild(shared_ptr<GuiElement>);
	virtual void removeChild(shared_ptr<GuiElement>);
	virtual void clearAll();
	const vector<shared_ptr<GuiElement>> &getChildren();
};
