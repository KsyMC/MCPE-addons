#pragma once

class ItemInstance;
class Random;

// Size : 33
class FishReward {
public:
	int probability;	// 4
	ItemInstance instance;	// 8
	float damage;	// 28
	bool enchanted;	// 32
public:
	FishReward(const ItemInstance&, int);
	virtual ~FishReward();
	void* getItem(Random&) const;
	void setDamage(float);
	void setEnchanted();
};