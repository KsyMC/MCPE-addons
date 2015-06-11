#pragma once

#include "Minecraft.h"
#include "settings/Options.h"

class ScreenChooser;
class LevelRenderer;
class GameRenderer;
class ParticleEngine;
class ExternalServerFile;
class Textures;
class Font;
class Gui;
class SoundEngine;
class GameStore;
class SkinRepository;
class Screen;

// Size : 400
class MinecraftClient : public Minecraft
{
public:
	static int _hasInitedStatics;

public:
	char filler1[4];						// 248
	ScreenChooser *chooser;					// 252
	char filler2[36];						// 256
	LevelRenderer *levelRenderer;			// 292
	GameRenderer *gameRenderer;				// 296
	ParticleEngine *particleEngine;			// 300
	ExternalServerFile *externalServerFile;	// 304
	Textures *textures;						// 308
	Font *font;								// 312
	char filler3[16];						// 316
	LocalPlayer *player;					// 332
	Gui *gui;								// 336
	Options *options;						// 340
	SoundEngine *soundEngine;				// 344
	char filler4[8];						// 348
	GameStore *gameStore;					// 356
	SkinRepository *skinRepository;			// 360
	char filler5[36];						// 364

public:
	MinecraftClient(int, char **);
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
	virtual void setTextboxText(std::string const&);
	virtual void setSize(int, int, float);
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void init();
	virtual void teardown();
	virtual void selectLevel(const std::string &, const std::string &, const LevelSettings &);
	virtual void setLevel(std::unique_ptr<Level>, const std::string &, Player *);
	virtual void startFrame();
	virtual void updateGraphics(const Timer &);
	virtual void endFrame();
	virtual void tick(int, int);
	virtual void leaveGame(bool);
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	virtual void isServerVisible();
	virtual void sendLocalMessage(const std::string &, const std::string &);
	virtual void getPlayer();
	virtual void onInternetUpdate();
	virtual void createLocalClientNetworkHandler();
	virtual void getSoundPlayer();
	virtual void getVibration();
	virtual void getLocalPlayer();
	virtual void vibrate(int);
	void _createDefaultInput();
	void _reloadFancy(bool);
	void _reloadLanguages();
	void freeResources(bool);
	float getDpadScale();
	Gui *getGui();
	void *getOptions();
	SkinRepository *getSkinRepository();
	void grabMouse();
	void handleBackNoReturn();
	void handleMouseClick(int);
	void handleMouseDown(int, bool);
	void initFoliageAndTileTextureTessellator();
	void initGLStates();
	void initSnoopClient();
	void isKindleFire(int);
	void joinMultiplayer(char const *, int, bool);
	void locateMultiplayer();
	void onPlayerLoaded(Player &);
	void onUpdatedClient(int, int, int, int);
	void optionUpdated(const Options::Option *, bool);
	void optionUpdated(const Options::Option *, float);
	void optionUpdated(const Options::Option *, int);
	void rebuildLevel();
	void releaseMouse();
	void resetInput();
	void restartServer();
	void sendHardwareSnoopEvent();
	void setDpadScale(float);
	void setScreen(Screen *);
	bool supportNonTouchScreen();
	void tickInput();
	void transformResolution(int *, int *);
	void updateScheduledScreen();
	void updateStats();
	bool useController();
};
