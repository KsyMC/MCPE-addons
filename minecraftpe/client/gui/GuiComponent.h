#pragma once

#include "..\renderer\ScreenRenderer.h"

// Size : 64
class GuiComponent
{
public:
	//void **vtable;				// 0
	ScreenRenderer _screenRenderer;	// 4

public:
	GuiComponent();
	virtual ~GuiComponent();
};