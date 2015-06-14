#pragma once

#include <vector>
#include "GuiComponent.h"

namespace Touch
{
	class TButton;
}
namespace Controller
{
	class StickDirection;
}

class MinecraftClient;
class IntRectangle;
class Button;
class TextBox;
class GuiElement;
class MCOEvent;
class MojangConnectionStatus;

// Size : 200
class Screen : public GuiComponent
{
public:
	int width;								// 64
	int height;								// 68
	char filler1[4];						// 72
	MinecraftClient *mc;					// 76
	std::vector<Button *> buttonList;		// 80
	std::vector<TextBox *> textboxList;		// 92
	std::vector<Button *> buttonList2;		// 104
	std::vector<GuiElement *> elementList;	// 116
	std::vector<GuiElement *> elementList2;	// 128
	char filler5[12];						// 140
	Font *fontObj;							// 152
	Button *selectedButton;					// 156
	char filler6[28];						// 160
	MaterialPtr ui_cubemap;					// 188

public:
	Screen();
	virtual ~Screen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void updateEvents();
	virtual void mouseEvent();
	virtual void keyboardEvent();
	virtual void keyboardTextEvent();
	virtual void controllerEvent();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual void removed();
	virtual void renderBackground(int);
	virtual void renderDirtBackground();
	virtual void renderMenuBackground(float);
	virtual bool renderGameBehind();
	virtual void hasClippingArea(IntRectangle &);
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual bool closeOnPlayerHurt();
	virtual void confirmResult(bool, int);
	virtual void lostFocus();
	virtual void toGUICoordinate(int &, int &);
	virtual void feedMCOEvent(MCOEvent);
	virtual void supppressedBySubWindow();
	virtual void onTextBoxUpdated(int);
	virtual void onMojangConnectorStatus(MojangConnectionStatus);
	virtual void setTextboxText(const std::string &);
	virtual void onInternetUpdate();
	virtual void updateTabButtonSelection();
	virtual void buttonClicked(Button *);
	virtual void guiElementClicked(GuiElement *);
	virtual void mouseClicked(int, int, int);
	virtual void mouseReleased(int, int, int);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void controllerDirectionHeld(int, Controller::StickDirection);
	virtual void keyPressed(int);
	virtual void keyboardNewChar(const std::string &, bool);
	virtual void shouldSendAllKeyStates();
	void _init(MinecraftClient &, int, int);
	void getCursorMoveThrottle();
	void getPassGuiEvents();
	void processControllerDirection(int);
	void setPassGuiEvents(bool);
	void setSize(int, int);
	void tabNext();
	void tabPrev();
	void renderProgressBar(float) const;
};
