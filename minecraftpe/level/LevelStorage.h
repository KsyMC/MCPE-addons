#pragma once

#include <memory>
#include <string>

class LevelData;
class ChunkSource;
class Player;
typedef int StorageVersion;

class LevelStorage
{
	virtual ~LevelStorage();
	virtual void loadLevelData(LevelData &) = 0;
	virtual void createChunkStorage(std::unique_ptr<ChunkSource>, StorageVersion) = 0;
	virtual void saveLevelData(LevelData &) = 0;
	virtual void getFullPath() const = 0;
	virtual void savePlayerData(const std::string &, const std::string &) = 0;
	virtual void saveData(const std::string &, const std::string &) = 0;
	virtual void isCorrupted() const = 0;
	virtual void loadData(const std::string &);
	virtual void getState() const = 0;
	virtual void loadPlayerData(const std::string &) = 0;
	virtual void loadAllPlayerIDs() = 0;
	virtual void save(Player &) = 0;
};
