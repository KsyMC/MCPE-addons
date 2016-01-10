#pragma once

#include <vector>
#include <memory>

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
	virtual void handleTextChar(MinecraftClient *, const std::string &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void setKeyboardHeight(MinecraftClient *, float, const Vec2 &);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void hasChildren() const;
	virtual void addChild(std::shared_ptr<GuiElement>);
	virtual void removeChild(std::shared_ptr<GuiElement>);
	virtual void clearAll();
	const std::vector<std::shared_ptr<GuiElement>> &getChildren();
};
