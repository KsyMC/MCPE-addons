#pragma once

#include "AppPlatform_android.h"

class AppPlatform_android23 : public AppPlatform_android
{
public:
	virtual ~AppPlatform_android23();
	virtual void readAssetFile(const std::string &);
	virtual void initWithActivity(ANativeActivity *);
};
