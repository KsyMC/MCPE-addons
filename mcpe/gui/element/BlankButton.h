#ifndef __BLANKBUTTON_H__
#define __BLANKBUTTON_H__

#include "Button.h"

class BlankButton : public Button {
public:
	// Size : 120

public:
	BlankButton(int);
	BlankButton(int, int, int, int);
	virtual ~BlankButton();
};

#endif
