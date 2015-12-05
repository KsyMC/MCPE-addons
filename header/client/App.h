#pragma once

#include <string>
#include "AppPlatformListener.h"

// Size : 28
class App : public AppPlatformListener
{
public:
	char filler1[24]; 	// 4

public:
	App(int, char **);
	virtual ~App();
	virtual void platform();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void destroy();
	virtual void loadState(void *, int);
	virtual void saveState(void **, int *);
	virtual void useTouchscreen();
	virtual void setTextboxText(const std::string &);
	virtual void draw();
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void quit();
	virtual void wantToQuit();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void init();
};
