#pragma once

#include <vector>
#include <memory>
#include "GuiElement.h"

// Size : 128
class GuiElementContainer : public GuiElement
{
public:
	std::vector<std::shared_ptr<GuiElement>> children;	// 108
	char filler1[8];									// 120

public:
	GuiElementContainer(bool, bool, int, int, int, int);
	virtual ~GuiElementContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual void focusedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, const std::string &, bool);
	virtual bool backPressed(MinecraftClient *, bool);
	virtual bool suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual bool hasChildren() const;
	virtual void addChild(std::shared_ptr<GuiElement>);
	virtual void removeChild(std::shared_ptr<GuiElement>);
	virtual void clearAll();
	const std::vector<std::shared_ptr<GuiElement>> &getChildren();
};
