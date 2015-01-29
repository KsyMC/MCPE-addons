#ifndef __DISCONNECTIONSCREEN_H__
#define __DISCONNECTIONSCREEN_H__

#include "Screen.h"

namespace Touch {
	class TButton;
}
class Button;

class DisconnectionScreen : public Screen {
	public:
	// Size : 208
	std::string _text;			// 200
	Touch::TButton *_okButton;	// 204

public:
	DisconnectionScreen(std::string text) {
		_text = text;
		_okButton = NULL;
	}
	virtual ~DisconnectionScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual bool isInGameScreen();
	virtual void buttonClicked(Button *);
};

#endif
