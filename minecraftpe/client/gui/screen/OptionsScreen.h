#pragma once

#include <vector>

class MinecraftClient;
class OptionsPane;

// Size : 288
class OptionsScreen
{
public:
	char filler1[20];				// 0
	MinecraftClient *client;		// 20
	char filler2[140];				// 24
	std::vector<std::shared_ptr<OptionsPane>> vectorPanes;	// 164

public:
	OptionsScreen();
	virtual ~OptionsScreen();
	virtual void onSetKeyboardHeight(float);
	virtual void removed();
	virtual void onFocusGained();
	virtual void handleButtonRelease(short);
	virtual void handleBackEvent(bool);
	virtual void handleTextChar(std::string const &, bool);
	virtual void setTextboxText(std::string const &);
	virtual void renderGameBehind() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void handleScrollWheel(float);
	virtual void _buttonClicked(Button&);
	virtual void _pointerPressed(int, int);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
	virtual void generateOptionScreens();
	virtual void createCategoryButtons();
	virtual void renderBgFill();
	void _generateOptionScreensDefault();
};
