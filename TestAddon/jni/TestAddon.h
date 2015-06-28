#pragma once

#include "Addon.h"

class TestAddon : public Addon
{
public:
	TestAddon();
	virtual ~TestAddon();
	virtual std::string getName();
	virtual std::string getVersion();
	virtual int getVersionCode();
	virtual std::string getDescription();
};
