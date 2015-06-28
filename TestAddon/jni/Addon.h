#pragma once

#include <string>

class Screen;

class Addon
{
public:
	Addon();
	virtual ~Addon();
	virtual void onEnable();
	virtual void onDisable();
	virtual Screen *getOptionsScreen(Screen *backScreen);
	virtual std::string getName();
	virtual std::string getVersion();
	virtual int getVersionCode();
	virtual std::string getDescription();
};
