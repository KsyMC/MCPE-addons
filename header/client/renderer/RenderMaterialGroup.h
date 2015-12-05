#pragma once

#include "../AppPlatformListener.h"

class RenderMaterialGroup : public AppPlatformListener
{
public:
	RenderMaterialGroup();
	virtual void ~RenderMaterialGroup();
	virtual void onAppSuspended();
	virtual void onAppResumed();
};
