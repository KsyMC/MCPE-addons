#pragma once

#include <functional>
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
class Music;

// Size : 400
class MinecraftClient : public App
{
public:
	static int INTERACTION_FREQ_MS;
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
	void _getGuiScaleFromHeight(int, float);
	void _getGuiScaleFromWidth(int, float);
	void _initMinecraftClient();
	void _popScreen();
	void _processNewGazeHoloScreenData();
	void _reloadFancy(bool);
	void _reloadLanguages();
	void _setNewGazeHoloScreenDirection(Vec3);
	void _setNewGazeHoloScreenPosition(Vec3);
	void allowPicking();
	void cancelLocateMultiplayer();
	void checkForPiracy();
	void clearDictationDataAvailable();
	void endFrame();
	void forEachScreen(std::function<bool (std::shared_ptr<AbstractScreen> &)>);
	void forEachVisibleScreen(std::function<void (std::shared_ptr<AbstractScreen> &)>);
	void freeResources(bool);
	void getCameraTargetPlayer() const;
	void getClientRandomId() const;
	void getClientUUID() const;
	void getConnectedPort() const;
	void getConnectedServer() const;
	void getDictationText() const;
	float getDpadScale();
	void getExternalServer() const;
	Font *getFont() const;
	GameRenderer *getGameRenderer() const;
	void getGameStore() const;
	Gui *getGui() const;
	int getHeight() const;
	void getHoloInput() const;
	void getHolosceneRenderer() const;
	void getHoloscreenHalfWidth() const;
	void getHoloviewerScale();
	void getInput() const;
	void getKeyboardHeight() const;
	void getLevelRenderer() const;
	void getLocalPlayer();
	void getMouseGrabbed() const;
	void getMultiplayer() const;
	void getOptions();
	void getParticleEngine() const;
	void getRuneFont() const;
	Screen *getScreen();
	Screen *getScreen() const;
	ScreenChooser *getScreenChooser() const;
	void getServer();
	Music *getSituationalMusic();
	void getSkinRepository();
	void getSoundEngine() const;
	void getTelemetry() const;
	void getTextures() const;
	void getUIDefStore() const;
	void getVoiceSystem() const;
	void getUserManager() const;
	int getWidth() const;
	void grabMouse();
	void handleAttackActionButtonRelease();
	void handleBackNoReturn();
	void handleBiomeDisplayButtonPress();
	void handleBuildActionButtonRelease();
	void handleBuildAction(BuildActionIntention &);
	void handleBuildOrAttackButtonPress();
	void handleCaretLocation(int);
	void handleBuildOrInteractButtonPress();
	void handleChatButtonPress();
	void handleConsoleButtonPress();
	void handleCommandEvent(VoiceCommand const &);
	void handleCraftingButtonPress();
	void handleCreativeBlockSelectButtonRelease();
	void handleDebugToggleAnchorsCommand();
	void handleDebugToggleLSRCommand();
	void handleDecreaseRenderDistanceButtonPress();
	void handleDecrementMaxCullingStepsButtonPress();
	void handleDestoryOrAttackButtonPress();
	void handleDestroyOrInteractButtonPress();
	void handleDictationEvent();
	void handleDirection(DirectionId, float, float);
	void handleDismountButtonPress();
	void handleDropAllButtonPress();
	void handleDropAllItemsButtonPress();
	void handleDropButtonPress();
	void handleHideGuiButtonPress();
	void handleIncreaseRenderDistanceButtonPress();
	void handleIncrementMaxCullingStepsButtonPress();
	void handleInputModeChanged(InputMode);
	void handleInteractButtonPress();
	void handleInventoryButtonPress();
	void handleInventoryMoveButtonPress(int);
	void handleInvite();
	void handleLicenseChanged();
	void handleLowMemoryWarningButtonPress();
	void handleMemoryStatsButtonPress();
	void handleMenuButtonPress(short);
	void handleMenuButtonRelease(short);
	void handleMobEffectsButtonPress();
	void handleNextAVCStatButtonPress();
	void handleNextAVCStatButtonRelease();
	void handlePaddleButtonPress(Side);
	void handlePaddleButtonRelease(Side);
	void handlePauseButtonPress();
	void handlePickDebugObjectButtonPress();
	void handlePointerLocation(short, short);
	void handlePointerPressedButtonPress();
	void handlePointerPressedButtonRelease();
	void handleRedstoneLogButtonPress();
	void handleReloadUIDefinitions();
	void handleRenderDebugButtonPress();
	void handleSetSpawnPositionButtonPress();
	void handleShowUpsellScreen(bool);
	void handleSlotSelectButtonPress(int);
	void handleSuspendResumeButtonPress();
	void handleTextChar(std::string const &, bool);
	void handleTimePause(bool);
	void handleTimeScale(float);
	void handleTimeStepForwardButtonPress();
	void handleToggleAdvancedCullingButtonPress();
	void handleToggleDayCycleActiveButtonPress();
	void handleToggleEnableNewScreensButtonPress();
	void handleToggleEnableNewScreensDebugButtonPress();
	void handleToggleFlyFlastButtonPress();
	void handleToggleFrameTimerDisplayButtonPress();
	void handleToggleGameModeButtonPress();
	void handleToggleNoClipButtonPress();
	void handleTogglePlayerUpdateMobsButtonPress();
	void handleToggleShowChunkMapButtonPress();
	void handleToggleSimulateTouchButtonPress();
	void handleToggleThirdPersonViewButtonPress();
	void handleVectorInput(short, float, float, float);
	void initFoliageAndBlockTextureTessellator();
	void initOptionObservers();
	void initSnoopClient();
	void initializeTrialWorld(Player *);
	bool isKindleFire(int);
	bool isSRPlacementMode() const;
	bool isScreenReplaceable() const;
	bool isServerVisible();
	bool isShowingMenu() const;
	void joinLiveGame(std::string const &);
	void joinMultiplayer(char const*, int, bool);
	void leaveGame(bool);
	void locateMultiplayer();
	void muteAudio();
	void newDictationDataAvailable() const;
	void onClientStartedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
	void onDimensionChanged();
	void onGameEventNotification(UI::GameEventNotification);
	void onGameModeChanged();
	void onMobEffectsChange();
	void onPlayerLoaded(Player  &);
	void onPrepChangeDimension();
	void onStereoEnabledChanged();
	void onUserSignin();
	void onUserSignout();
	void play(std::string const &, Vec3 const &, float, float);
	void playUI(std::string const &, float, float);
	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void popScreen(int);
	void refocusMouse();
	void registerUpsellScreen();
	void releaseMouse();
	void reloadShaders();
	void resetInhibitInputDueToTextBoxMode();
	void restartServer();
	void resetInput();
	void sendHardwareSnoopEvent();
	void setCameraTargetPlayer(Mob *);
	void sendLocalMessage(std::string const &, std::string const &);
	void setDpadScale(float);
	void setGameMode(GameType);
	void setHoloInput(std::unique_ptr<HolographicPlatform>);
	void setHoloscreenHalfWidth(float);
	void setHoloviewerPlayerMode(bool, bool);
	void setInhibitInputDueToTextBoxMode();
	void setKeyboardHeight(float);
	void setInviteHandle(std::string const &);
	void setSuspendInput(bool);
	void setVoiceSystem(std::unique_ptr<VoiceSystem>);
	void setupCommandParser();
	void setupLevelRendering(Level *, Dimension *, Mob *);
	void setupRenderer();
	void startFrame();
	void startHoloviewerReveal();
	void startLocalServer(std::string, std::string, LevelSettings);
	void teardownRenderer();
	void tickBuildAction();
	void tickInput();
	void toggleThirdPersonView();
	void transformResolution(int *, int *);
	void updateGraphics(Timer const &);
	void updateScheduledScreen();
	void updateStats();
	void useController();
};
