#pragma once

#include "minecraftpe/client/renderer/entity/MobRenderer.h"

class HorseRenderer : public MobRenderer
{
public:
	HorseRenderer(Model *, float);
	virtual ~HorseRenderer();
};
