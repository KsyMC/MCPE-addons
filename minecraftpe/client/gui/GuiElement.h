#pragma once

#include <string>
#include "GuiComponent.h"
#include "../../util/Color.h"

namespace Controller
{
	class StickDirection;
}

class MinecraftClient;
class NinePatchLayer;

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
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual void focusedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, const std::string &, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void handleControllerDirectionHeld(int, Controller::StickDirection);
	virtual void drawSelected(int);
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
