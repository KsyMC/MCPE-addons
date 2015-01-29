#ifndef __GUICOMPONENT_H__
#define __GUICOMPONENT_H__

#include "ScreenRenderer.h"

class GuiComponent {
public:
	// Size : 64
	//void **vtable;							// 0
	ScreenRenderer _screenRenderer;	// 4

	GuiComponent();
	virtual ~GuiComponent();
};

#endif
