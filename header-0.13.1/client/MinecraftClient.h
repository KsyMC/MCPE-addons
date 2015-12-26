#pragma once

#include "minecraftpe/client/App.h"
#include "minecraftpe/client/resources/SkinInfoFactory.h"
#include "minecraftpe/client/resources/SkinInfoData.h"
#include "minecraftpe/level/LevelSettings.h"

class LocalPlayer;
class Minecraft;
class Options;
class Gui;

class MinecraftClient : public App, /*public idk1, public idk2, */public SkinInfoFactory
{
public:
	//void **vtable;	// 28
	//void **vtable;	// 32
	char vtable[4];		// 36
	char filler2[24];	// 36
	string worldDir;	// 60
	string dataDir;		// 64

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
	virtual void setTextboxText(string const &);
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void init();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void onInternetUpdate();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual unique_ptr<SkinInfoData> createSkin(bool, bool);
	virtual void onTick(int, int);
	virtual void vibrate(int);
	void initOptionObservers();
	void leaveGame(bool);
	Options *getOptions();
	int getWidth() const;
	int getHeight() const;
	LocalPlayer *getLocalPlayer();
	Minecraft *getServer();
	Gui *getGui() const;
	void startLocalServer(string, string, LevelSettings);
};
