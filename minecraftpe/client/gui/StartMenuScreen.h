#pragma once

#include "Screen.h"
#include "TButton.h"

class ImageWithBackground;

namespace Touch
{

// Size : 592
class StartMenuScreen : public Screen
{
public:
	static int currentSplash;

public:
	Touch::TButton playButton;			// 200
	Touch::TButton realmButton;			// 376
	ImageWithBackground *optionButton;	// 552
	ImageWithBackground *languageButton;// 556
	char filler1[32];					// 560

public:
	StartMenuScreen();
	virtual ~StartMenuScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual bool isInGameScreen();
	virtual void buttonClicked(Button *);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
};

}
