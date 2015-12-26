#pragma once

#include "minecraftpe/level/LevelStorage.h"

class DBStorage : public LevelStorage
{
public:
	virtual ~DBStorage();
	virtual void loadLevelData(LevelData &);
	virtual void createChunkStorage(unique_ptr<ChunkSource>, StorageVersion);
	virtual void saveLevelData(LevelData &);
	virtual void getFullPath() const;
	virtual void savePlayerData(string const &, string &&);
	virtual void saveData(string const &, string &&);
	virtual void isCorrupted() const;
	virtual void loadData(string const &);
	virtual void getState() const;
	virtual void loadPlayerData(string const &);
	virtual void loadAllPlayerIDs();
	virtual void save(Player &);
	virtual void getLevelId() const;
	virtual void pauseModificationsAndGetFiles();
	virtual void resumeModifications();
};
