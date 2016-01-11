#pragma once

#include "minecraftpe/gamemode/GameMode.h"

class SurvivalMode : public GameMode
{
public:
	SurvivalMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual void startDestroyBlock(Player &, BlockPos, signed char);
	virtual void destroyBlock(Player &, BlockPos, signed char);
	virtual void tick();
	virtual void useItem(Player&, ItemInstance &);
	virtual void useItemOn(Player&, ItemInstance *, const BlockPos &, signed char, const Vec3 &);
	virtual void setTrialMode(bool);
	virtual void isInTrialMode();
	virtual void registerUpsellScreenCallback(std::function<void (bool)>);
};
