#pragma once

#include "RandomStrollGoal.h"

class Silverfish;

// Size : 40
class SilverfishMergeWithStoneGoal : public RandomStrollGoal
{
public:
	SilverfishMergeWithStoneGoal(Silverfish *);
	virtual ~SilverfishMergeWithStoneGoal();
	virtual bool canUse();
	virtual bool canContinueToUse();
	virtual void start();
};
