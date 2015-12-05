#pragma once

#include "Button.h"

// Size : 108
class BlankButton : public Button
{
public:
	BlankButton(int);
	BlankButton(int, int, int, int, int);
	virtual ~BlankButton();
};
