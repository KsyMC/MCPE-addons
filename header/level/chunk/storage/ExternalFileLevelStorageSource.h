#pragma once

#include <string>
#include <vector>

class LevelSummary;
class LevelData;
class ProgressListener;

// Size : 8
class ExternalFileLevelStorageSource
{
public:
	ExternalFileLevelStorageSource(const std::string &);
	virtual ~ExternalFileLevelStorageSource();
	virtual void getName();
	virtual void getLevelList(std::vector<LevelSummary> &);
	virtual void getLevelData(const std::string &);
	virtual void setLevelData(const std::string &, const LevelData &);
	virtual void createLevelStorage(const std::string &);
	virtual void isNewLevelIdAcceptable(const std::string &);
	virtual void clearAll();
	virtual void deleteLevel(const std::string &);
	virtual void renameLevel(const std::string &, const std::string &);
	virtual void isConvertible(const std::string &);
	virtual void requiresConversion(const std::string &);
	virtual void convertLevel(const std::string &, ProgressListener *);
	virtual void getBasePath() const;
};
