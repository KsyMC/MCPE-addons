#pragma once

#include "minecraftpe/fishing/FishReward.h"

// Size : 36
class FishRewardMgr {
public:
	std::vector<FishReward*> trashList;	// 0
	std::vector<FishReward*> treasureList;	// 12
	std::vector<FishReward*> fishList;	// 24
public:
	FishRewardMgr();
	virtual ~FishRewardMgr();
	static FishRewardMgr* GetPtr();
	static void DeletePtr();
	void _init();
	std::vector<FishReward*> getFishList();
	void getTrashList(); // returns nothing
	std::vector<FishReward*> getTreasureList();
};