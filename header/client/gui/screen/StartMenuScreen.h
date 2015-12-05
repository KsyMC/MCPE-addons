#pragma once

#include "Screen.h"
#include "TButton.h"

class ImageWithBackground;

namespace Touch
{ // Size : 592
class StartMenuScreen : public Screen
{
public:
	static int mCurrentSplash;
	static std::vector<std::string> mSplashes;

public:
	Touch::TButton *playButton;							// 160
	std::shared_ptr<Touch::TButton> playButton_ptr;		// 164
	Touch::TButton realmButton;							// 168
	std::shared_ptr<Touch::TButton> realmButton_ptr;	// 172
	ImageWithBackground *optionButton;					// 176
	std::shared_ptr<Touch::TButton> optionButton_ptr;	// 180
	ImageWithBackground *languageButton;				// 184
	std::shared_ptr<Touch::TButton> languageButton_ptr;	// 188

public:
	StartMenuScreen();
	virtual ~StartMenuScreen();
	virtual void handleBackEvent(bool);
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void _buttonClicked(Button &);
	virtual void _controllerDirectionChanged(int, StickDirection);
};
};
