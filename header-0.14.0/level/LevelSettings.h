#pragma once

#include <string>

enum GameType;

// Size: 40
class LevelSettings {
public:
	unsigned int seed;	// 0
	int gameType;			// 4
	int generator;		// 8
	int loadedInCreative;	// 12
	int filler;			// 16
	int dayCycle;			// 20
	int eduWorld;			// 24
	int filler2[12];		// 28
public:
	LevelSettings();
	
	static std::string gameTypeToString(GameType);
	int getDayCycleStopTime() const;
	void* getDefaultSpawn() const;
	int getGameType() const;
	int getGenerator() const;
	unsigned int getSeed() const;
	int hasBeenLoadedInCreative() const;
	int isEduWorld() const;
	void parseSeedString(const std::string&, unsigned int);
	void setIsEduWorld(bool);
	void validateGameType(GameType);
};