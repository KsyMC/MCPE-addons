#pragma once

#include "minecraftpe/client/gui/Screen.h"

namespace Touch
{
	class THeader;
	class HeaderButton;
	class TButton;
}

class PackedScrollContainer;
class Label;
class Addon;

class AddonManagerScreen : public Screen
{
public:
	bool inGame;
	Touch::THeader *managerHeader;
	Touch::HeaderButton *backButton;
	PackedScrollContainer *addonContainer;
	Label *addonNameLabel;
	Label *addonDescLabel;
	Touch::TButton *optionsButton;
	Screen *optionsScreen;

public:
	AddonManagerScreen(bool);
	virtual ~AddonManagerScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	void setItem(Addon *);
	void closeScreen();
};
