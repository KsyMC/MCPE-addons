#pragma once

#include "Screen.h"
#include "../../level/LevelListener.h"

class Label;

// Size : 236
class PauseScreen : public Screen, public LevelListener
{
public:
	//void **vtable;				// 200
	char filler1[12];				// 204
	Touch::TButton *backButton;		// 216
	Touch::TButton *quitButton;		// 220
	Touch::TButton *quitCopyButton;	// 224
	Touch::TButton *optionButton;	// 228
	Label *gameMenuLabel;			// 232
	Label *playerList;				// 236

public:
	PauseScreen(bool);
	virtual ~PauseScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void handleBackEvent(bool);
	virtual void tick();
	virtual void renderGameBehind();
	virtual void buttonClicked(Button *);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
};
