#pragma once

#include <vector>
#include "GuiElement.h"
#include "../settings/Options.h"

//Size : 164
class Slider : public GuiElement
{
public:
	char filler1[56];

public:
	Slider(MinecraftClient &, const Options::Option *, float, float);
	Slider(MinecraftClient &, const Options::Option *, std::vector<int>);
	virtual ~Slider();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseRelased(MinecraftClient *, int, int, int);
	virtual void setOption(MinecraftClient *);
	void updateStepPercentage();
	void processControllerInput(MinecraftClient *, int);
};
