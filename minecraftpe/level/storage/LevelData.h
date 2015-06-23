#pragma once

#include <string>
#include "../GeneratorType.h"
#include "../../util/TilePos.h"
#include "../../nbt/CompoundTag.h"

namespace RakNet
{
	class BitStream;
}

class LevelSettings;
typedef int StorageVersion;
typedef int Dimension;

// Size : 108
class LevelData
{
public:
	std::string levelName;		// 0
	char filler1[12];			// 4
	unsigned int randomSeed;	// 16
	TilePos spawnPos;			// 20
	char filler2[12];			// 32
	int worldTime;				// 44
	long lastTimePlayed;		// 48
	CompoundTag playerTag;		// 52
	Dimension dimension;		// 84
	int theGameType;			// 88
	bool spawnMobs;				// 92
	int stopTime;				// 96
	GeneratorType terrainType;	// 100
	long totalTime;				// 104

public:
	LevelData();
	LevelData(const CompoundTag &);
	LevelData(const LevelSettings &, const std::string &, GeneratorType, const TilePos *);
	LevelData(LevelData &&);
	void clearLoadedPlayerTag();
	void createTag() const;
	Dimension getDimension();
	int getGameType() const;
	void getGenerator() const;
	void getLastPlayed() const;
	std::string getLevelName() const;
	void getLoadedPlayerTag();
	unsigned int getSeed() const;
	TilePos getSpawn() const;
	bool getSpawnMobs() const;
	void getTagData(const CompoundTag &);
	int getTime() const;
	void getWorldStartCount() const;
	bool operator=(LevelData &&);
	void recordStartUp();
	void setDimension(Dimension);
	void setGameType(int);
	void setGenerator(GeneratorType);
	void setLevelName(const std::string &);
	void setSeed(unsigned int);
	void setSpawn(const TilePos &);
	void setSpawnMobs(bool);
	void setStopTime(int);
	void setTagData(CompoundTag &) const;
	void setTime(int);
	void v1_read(RakNet::BitStream &, StorageVersion);
};
