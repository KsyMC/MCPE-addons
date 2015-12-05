#pragma once

#include <functional>
#include <string>
#include <vector>

class Options
{
public:
	class Option
	{
	public:
		static Option ANIMATE_TEXTURES;
		static Option AUTO_JUMP;
		static Option DESTROY_VIBRATION;
		static Option DIFFICULTY;
		static Option DPAD_SCALE;
		static Option FANCY_SKIES;
		static Option FIELD_OF_VIEW;
		static Option FULLSCREEN;
		static Option GAMEPAD_MAP;
		static Option GAMMA;
		static Option GRAPHICS;
		static Option GUI_SCALE;
		static Option HIDE_GUI;
		static Option INVERT_MOUSE;
		static Option KEYBOARD_LAYOUT;
		static Option LEFT_HANDED;
		static Option LIMIT_FRAMERATE;
		static Option LIMIT_WORLD_SIZE;
		static Option MULTIPLAYER_GAME;
		static Option MUSIC;
		static Option NAME;
		static Option RENDER_BOUNDING_BOXES;
		static Option RENDER_GOAL_STATE;
		static Option RENDER_PATHS;
		static Option RESET_CLIENT_ID;
		static Option SENSITIVITY;
		static Option SERVER_VISIBLE;
		static Option SHOW_CHUNK_MAP;
		static Option SOUND;
		static Option SPLIT_CONTROLS;
		static Option SWAP_JUMP_AND_SNEAK;
		static Option THIRD_PERSON;
		static Option USE_TOUCHSCREEN;
		static Option VIEW_BOBBING;
		static Option VIEW_DISTANCE;
		static Option XBOX_LIVE_VISIBLE;

	public:
		int type;			// 0
		const char *desc;	// 4

	public:
		~Option();
	};

public:
	static void *CAMERA_MODES;
	static void *DIFFICULTY_LEVELS;
	static const char *DIFFICULTY_NAMES[4];
	static float DPAD_SCALE_MAX_VALUE;
	static float DPAD_SCALE_MIN_VALUE;
	static float FIELD_OF_VIEW_MAX_VALUE;
	static float FIELD_OF_VIEW_MIN_VALUE;
	static const char *GUI_SCALE[4];
	static float MUSIC_MAX_VALUE;
	static float MUSIC_MIN_VALUE;
	static void *RENDERDISTANCE_LEVELS_2048PLUS;
	static void *RENDERDISTANCE_LEVELS_256PLUS;
	static void *RENDERDISTANCE_LEVELS_4096PLUS;
	static void *RENDERDISTANCE_LEVELS_512PLUS;
	static void *RENDERDISTANCE_LEVELS_LOMEM;
	static const char *RENDER_DISTANCE_NAMES[4];
	static float SENSITIVITY_MAX_VALUE;
	static float SENSITIVITY_MIN_VALUE;
	static float SOUND_MAX_VALUE;
	static float SOUND_MIN_VALUE;

public:
	std::string filepath;	// 0

public:
	Options(std::string const &);
	~Options();
	void _formatDescriptionString(char const *, char const **, int);
	void _initDefaultValues();
	void _load();
	void _renderDistanceLevels();
	void _setDifficulty(int);
	void canModify(Option const *);
	void checkVersionUpdate();
	void getBooleanValue(Option const *);
	void getDescription(Option const *, std::string);
	void getIntValue(Option const *);
	void getValues(Option const *);
	void hideOption(Option const *);
	void onScreenSizeChanged(int, int);
	void registerBoolObserver(void *, Option const &, std::function<void (bool)>);
	void registerFloatObserver(void *, Option const &, std::function<void (float)>);
	void registerIntObserver(void *, Option const &, std::function<void (int)>);
	void registerOptionLock(void *, Option const &, std::function<bool ()>);
	void registerStringObserver(void *, Option const &, std::function<void (std::string)>);
	void save();
	void set(Option const *, bool);
	void set(Option const *, float);
	void set(Option const *, int);
	void set(Option const *, std::string const &);
	void setAdditionalHiddenOptions(std::vector<Option const *> const &);
	void toggle(Option const *, int);
	void unregisterLocks(void *);
	void unregisterObserver(void *);
	void updateGameSensitivity();
	static bool _readBool(std::string const &, bool &);
	static float _readFloat(std::string const &, float &);
	static int _readInt(std::string const &, int &);

	// Set
	void setAutoJump(bool);
	void setBobView(bool);
	void setCameraSpeed(float);
	void setDestroyVibration(bool);
	void setDevAutoLoadLevel(bool);
	void setDevDisableFileSystem(bool);
	void setDevRenderBoundingBoxes(bool);
	void setDevRenderGoalState(bool);
	void setDevRenderPaths(bool);
	void setDevResetClientId(bool);
	void setDevShowChunkMap(bool);
	void setDifficulty(int);
	void setDpadScale(float);
	void setFancyGraphics(bool);
	void setFancySkies(bool);
	void setFieldOfView(float);
	void setFixedCamera(bool);
	void setFlatWorldLayers(std::string const &);
	void setFlySpeed(float);
	void setFullscreen(bool);
	void setGamePadCustomMap(std::string const &);
	void setGameSensitivity(float);
	void setGamma(float);
	void setGlDebug(bool);
	void setGuiScale(int);
	void setHideGui(bool);
	void setInvertYMouse(bool);
	void setIsFlying(bool);
	void setIsLeftHanded(bool);
	void setKeyboardLayout(int);
	void setLanguage(std::string const &);
	void setLastBetaVersion(int);
	void setLastCustomSkinId(std::string const &);
	void setLastMajorVersion(int);
	void setLastMinorVersion(int);
	void setLastPatchVersion(int);
	void setLimitFramerate(bool);
	void setLimitWorldSize(bool);
	void setMultiPlayerGame(bool);
	void setMusic(float);
	void setPlayerViewPerspective(int);
	void setPpmDpadSizeOld(float);
	void setPreferPolyTessellation(bool);
	void setRenderDebug(bool);
	void setSensitivity(float);
	void setServerVisible(bool);
	void setSkinId(std::string const &);
	void setSmoothCamera(bool);
	void setSound(float);
	void setSplitControls(bool);
	void setSwapJumpAndSneak(bool);
	void setUseMouseForDigging(bool);
	void setUseTouchScreen(bool);
	void setUsername(std::string const &);
	void setViewDistanceBlocks(int);
	void setXboxLiveVisible(bool);

	// Get
	void getAnimateTextures() const;
	void getAutoJump() const;
	void getBobView() const;
	void getCameraSpeed() const;
	bool isFlying() const;
	bool isLeftHanded() const;
	void getRenderDebug() const;
	void getSensitivity() const;
	void getServerVisible() const;
	void getSkinId() const;
	void getSmoothCamera() const;
	void getSound() const;
	void getSplitControls() const;
	void getSwapJumpAndSneak() const;
	void getUseMouseForDigging() const;
	void getUseTouchScreen() const;
	void getUsername() const;
	void getViewDistanceBlocks() const;
	void getXboxLiveVisible() const;
	void getMultiPlayerGame() const;
	void getMusic() const;
	void getPlayerViewPerspective() const;
	void getPpmDpadSizeOld() const;
	void getPreferPolyTessellation() const;
	void getDestroyVibration() const;
	void getDevAutoLoadLevel() const;
	void getDevDisableFileSystem() const;
	void getDevRenderBoundingBoxes() const;
	void getDevRenderGoalState() const;
	void getDevRenderPaths() const;
	void getDevResetClientId() const;
	void getDevShowChunkMap() const;
	void getDifficulty() const;
	void getDpadScale() const;
	void getFancyGraphics() const;
	void getFancySkies() const;
	void getFieldOfView() const;
	void getFixedCamera() const;
	void getFlatWorldLayers() const;
	void getFlySpeed() const;
	void getFullscreen() const;
	void getGLDebug() const;
	void getGamePadCustomMap() const;
	void getGameSensitivity() const;
	void getGamma() const;
	void getGuiScale() const;
	void getHideGui() const;
	void getInvertYMouse() const;
	void getKeyboardLayout() const;
	void getLanguage() const;
	void getLastBetaVersion() const;
	void getLastCustomSkinId() const;
	void getLastMajorVersion() const;
	void getLastMinorVersion() const;
	void getLastPatchVersion() const;
	void getLimitFramerate() const;
	void getLimitWorldSize() const;
};
