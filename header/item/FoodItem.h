#pragma once

#include "Item.h"

// Size : 100
class FoodItem : public Item
{
public:
	int healAmount;					// 72
	float saturationModifier;		// 76
	bool isWolfsFavoriteMeat;		// 80
	int potionId;					// 84
	int potionDuration;				// 88
	int potionAmplifier;			// 92
	float potionEffectProbability;	// 96

public:
	FoodItem(int, int, bool, float);
	virtual ~FoodItem();
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual int getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual ActionEnum getUseAnimation() const;
	virtual bool isFood() const;
	virtual void addEatEffect(ItemInstance *, Level *, Player *);
	int getNutrition() const;
	float getSaturationModifier() const;
	bool isMeat() const;
	void setEatEffect(int, int, int, float);
};
