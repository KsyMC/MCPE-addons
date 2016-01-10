#pragma once

#include <memory>

#include "minecraftpe/client/resources/SkinInfoData.h"

class SkinInfoFactory
{
public:
	//void **vtable;	// 0

	virtual ~SkinInfoFactory();
	virtual std::unique_ptr<SkinInfoData> createSkin(bool, bool) = 0;
};
