#pragma once

#include <string>
#include <vector>

class MinecraftClient;

class Options
{
public:
	class Option
	{
	public:
		/*static void GAMMA, LIMIT_WORLD_SIZE, NAME, PIXELS_PER_MILLIMETER, ANIMATE_TEXTURES;
		static void FANCY_SKIES, DESTROY_VIBRATION, USE_TOUCH_JOYPAD, USE_TOUCHSCREEN;
		static void LEFT_HANDED, SERVER_VISIBLE, HIDE_GUI, THIRD_PERSON, GUI_SCALE, GRAPHICS;
		static void DIFFICULTY, LIMIT_FRAMERATE, VIEW_BOBBING, VIEW_DISTANCE, SENSITIVITY;
		static void INVERT_MOUSE, SOUND, MUSIC;*/
		~Option();
	};

public:
	/*static void RENDERDISTANCE_LEVELS_LOMEM, RENDERDISTANCE_LEVELS_256PLUS, RENDERDISTANCE_LEVELS_512PLUS;
	static void DIFFICULTY_LEVELS;
	static float PIXELS_PER_MILLIMETER_MAX_VALUE, PIXELS_PER_MILLIMETER_MIN_VALUE;
	static float SENSITIVITY_MAX_VALUE, SENSITIVITY_MIN_VALUE;
	static float MUSIC_MAX_VALUE, MUSIC_MIN_VALUE;
	static float SOUND_MAX_VALUE, SOUND_MIN_VALUE;*/
	static void *debugGl;

public:
	float music;				// 0
	float sound;				// 4
	float sensitivity;			// 8
	char filler1[4];			// 12
	bool invertMouse;			// 16
	int viewDistance;			// 20
	bool viewBobbing;			// 24
	bool limitFramerate;		// 25
	bool graphics;				// 26
	char filler2[2];			// 27
	bool leftHanded;			// 29
	bool destroyVibration;		// 30
	char filler3[205];			// 31
	int difficulty;				// 236
	bool hideGUI;				// 240
	bool thirdPerson;			// 241
	float gamma;				// 244
	char filler4[16];			// 248
	std::string name;			// 264
	bool serverVisible;			// 268
	bool useTouchJoypad;		// 269
	bool useTouchScreen;		// 270
	bool fancySkies;			// 271
	bool animateTextures;		// 272
	char filler5[19];			// 273
	float pixelsPerMillimeter;	// 292
	bool limitWorldSize;		// 299

public:
	~Options();
	void _renderDistanceLevels();
	bool canModify(const Options::Option *);
	void formatDescriptionString(const char *, const char **, int);
	bool getBooleanValue(const Options::Option *);
	std::string getDescription(const Options::Option *, std::string);
	int getIntValue(const Options::Option *);
	std::string getKeyDescription(int);
	std::string getKeyMessage(int);
	std::string getMessage(const Options::Option *);
	float getProgressMax(const Options::Option *);
	float getProgressMin(const Options::Option *);
	float getProgressValue(const Options::Option *);
	std::string getStringValue(const Options::Option *);
	float getValues(const Options::Option *);
	bool hideOption(const Options::Option *);
	void init(MinecraftClient *, const std::string &);
	void initDefaultValues();
	void notifyOptionUpdate(const Options::Option *, bool);
	void notifyOptionUpdate(const Options::Option *, float);
	void notifyOptionUpdate(const Options::Option *, int);
	void onScreenSizeChanged(int, int);
	void readBool(const std::string &, bool &);
	void readFloat(const std::string &, float &);
	void readInt(const std::string &, int &);
	void save();
	void set(const Options::Option *, float);
	void set(const Options::Option *, int);
	void set(const Options::Option *, const std::string &);
	void setAdditionalHiddenOptions(const std::vector<const Options::Option *> &);
	void setDefaultSkinType();
	void setKey(int, int);
	void toggle(const Options::Option *, int);
	void update();
	void updateGameSensitivity();
	void validateVersion();
};
