#pragma once

#include "Screen.h"

// Size : 208
class DisconnectionScreen : public Screen
{
public:
	std::string _text;			// 200
	Touch::TButton *_okButton;	// 204

public:
	DisconnectionScreen(const std::string &);
	virtual ~DisconnectionScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual bool handleBackEvent(bool);
	virtual bool isInGameScreen();
	virtual void buttonClicked(Button *);
};