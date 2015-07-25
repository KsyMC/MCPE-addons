#pragma once

#include "Addon.h"

class AddonManagerAddon : public Addon
{
public:
	AddonManagerAddon();
	virtual ~AddonManagerAddon();
	virtual Screen *getOptionsScreen(Screen *backScreen);
	virtual std::string getName();
	virtual std::string getVersion();
	virtual int getVersionCode();
	virtual std::string getDescription();
};
