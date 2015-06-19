#pragma once

#include "minecraftpe/client/gui/Screen.h"

namespace Touch
{
	class THeader;
	class HeaderButton;
	class TButton;
}

class NinePatchLayer;
class BlankButton;
class Label;
class ImageButton;
class PackedScrollContainer;

class TestScreen : public Screen
{
public:
	Touch::THeader *testHeader;
	Touch::HeaderButton *backButton;
	NinePatchLayer *backgroundLayer;
	BlankButton *blankButton;
	Label *stringLabel;
	ImageButton *imageButton;
	Label *stateLabel;
	Touch::TButton *testButton;
	Touch::TButton *toggleButton;
	PackedScrollContainer *container;

public:
	TestScreen();
	virtual ~TestScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
};
