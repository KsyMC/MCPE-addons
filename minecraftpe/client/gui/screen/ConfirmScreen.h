#pragma once

#include "Screen.h"

// Size : 232
class ConfirmScreen : public Screen
{
public:
	char filler1[8];			// 200
	std::string titleString;	// 208
	std::string descString;		// 212
	std::string okString;		// 216
	std::string cancelString;	// 220
	char filler2[8];			// 224

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
