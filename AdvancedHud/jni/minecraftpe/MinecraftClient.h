#pragma once

#include "App.h"

class MinecraftClient : public App
{
public:
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void useTouchscreen();
	virtual void setTextboxText(std::string const &);
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void init();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void onInternetUpdate();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual void createSkin(bool, bool);
	virtual void onTick(int, int);
	virtual void vibrate(int);
	int getWidth() const;
	int getHeight() const;
};
