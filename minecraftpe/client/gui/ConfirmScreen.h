#pragma once

#include "Screen.h"

class ConfirmScreen : public Screen
{
public:
	// Size : 232
	char filler1[32];	// 200

public:
	ConfirmScreen(Screen *, const std::string &, const std::string &, int);
	ConfirmScreen(Screen *, const std::string &, const std::string &, const std::string &, const std::string &, int);
	virtual ~ConfirmScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void postResult(bool);
};