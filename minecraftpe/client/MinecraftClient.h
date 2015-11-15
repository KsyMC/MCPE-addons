#pragma once

#include <functional>
#include <memory>
#include "App.h"
#include "../gamemode/GameType.h"
#include "../util/Vec3.h"

class AbstractScreen;
class Font;
class GameRenderer;
class Gui;
class Screen;
class ScreenChooser;
class Minecraft;
class Music;
class BuildActionIntention;
class Level;
class Mob;
class Dimension;
class Timer;
class Options;
class VoiceCommand;
class DirectionId;
class InputMode;
class Side;
class HolographicPlatform;
class VoiceSystem;
class Player;
class LocalPlayer;
class LevelSettings;
namespace UI
{
	class GameEventNotification;
};

// Size : 472
class MinecraftClient : public App
{
public:
	static int INTERACTION_FREQ_MS;
	static int _hasInitedStatics;

public:
	char filler1[68];		// 4
	int width;				// 72
	int height;				// 76
	Minecraft *minecraft;	// 80
	Font *font;				// 108
	Gui *gui;				// 288
	Options *options;		// 296
	ScreenChooser *screenChooser;	// 348

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
	bool allowPicking();
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
	Options *getOptions();
	void getParticleEngine() const;
	void getRuneFont() const;
	Screen *getScreen();
	Screen *getScreen() const;
	ScreenChooser *getScreenChooser() const;
	Minecraft *getServer();
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
	void newDictationDataAvailable() const;
	void onClientStartedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
	void onDimensionChanged();
	void onGameEventNotification(UI::GameEventNotification);
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
