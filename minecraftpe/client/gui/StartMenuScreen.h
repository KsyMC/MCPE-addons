#pragma once

#include "minecraftpe/client/gui/Screen.h"
#include "minecraftpe/client/gui/TButton.h"

class ImageWithBackground;

namespace Touch {
class StartMenuScreen : public Screen {
public:
	static int currentSplash;

public:
	// Size : 496
	Touch::TButton _playButton;			// 200
	Touch::TButton _realmButton;		// 328
	ImageWithBackground *_optionButton;	// 456
	char filler1[36];					// 460

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
