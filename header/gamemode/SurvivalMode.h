#pragma once

#include "GameMode.h"

class SoundPlayer;

// Size : 48
class SurvivalMode : public GameMode
{
public:
	char filler1[16];	// 32

public:
	SurvivalMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual ~SurvivalMode();
	virtual void startDestroyBlock(Player &, BlockPos, signed char);
	virtual void destroyBlock(Player &, BlockPos, signed char);
	virtual void tick();
	virtual void useItem(Player &, ItemInstance &);
	virtual void useItemOn(Player &, ItemInstance *, BlockPos const &, signed char, Vec3 const &);
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode();
	virtual void registerUpsellScreenCallback(std::function<void (bool)>);
};
