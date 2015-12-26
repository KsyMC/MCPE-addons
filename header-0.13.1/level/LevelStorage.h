#pragma once

#include "shared.h"
#include "minecraftpe/level/ChunkSource.h"
#include "minecraftpe/StorageVersion.h"

class LevelData;
class Player;

class LevelStorage
{
public:
	virtual ~LevelStorage();
	virtual void loadLevelData(LevelData &) = 0;
	virtual void createChunkStorage(unique_ptr<ChunkSource>, StorageVersion) = 0;
	virtual void saveLevelData(LevelData &) = 0;
	virtual void getFullPath() const = 0;
	virtual void savePlayerData(string const &, string &&) = 0;
	virtual void saveData(string const &, string &&) = 0;
	virtual void isCorrupted() const = 0;
	virtual void loadData(string const &);
	virtual void getState() const = 0;
	virtual void loadPlayerData(string const &) = 0;
	virtual void loadAllPlayerIDs() = 0;
	virtual void save(Player &) = 0;
	virtual void getLevelId() const = 0;
	virtual void pauseModificationsAndGetFiles() = 0;
	virtual void resumeModifications() = 0;
	unique_ptr<CompoundTag> loadPlayerData(Player const &);
};
