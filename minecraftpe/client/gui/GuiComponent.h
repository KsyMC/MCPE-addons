#pragma once

#include "../renderer/ScreenRenderer.h"

// Size : 4
class GuiComponent : public ScreenRenderer
{
public:
	//void **vtable;				// 0

public:
	GuiComponent();
	virtual ~GuiComponent();
};
