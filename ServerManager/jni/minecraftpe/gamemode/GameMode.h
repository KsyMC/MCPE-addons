#pragma once

#include <functional>

class PacketSender;
class Player;
class InputMode;
class BlockPos;
class Entity;
class Vec3;
class SoundPlayer;
class Vibration;

class GameMode
{
public:
	GameMode(PacketSender &, Level &, SoundPlayer &, Vibration &);
	virtual ~GameMode();
	virtual void startDestroyBlock(Player &, BlockPos, signed char);
	virtual void destroyBlock(Player &, BlockPos, signed char);
	virtual void continueDestroyBlock(Player&, BlockPos, signed char);
	virtual void stopDestroyBlock(Player &);
	virtual void startBuildBlock(Player &, BlockPos, signed char);
	virtual void buildBlock(Player &, BlockPos, signed char);
	virtual void continueBuildBlock(Player &, BlockPos, signed char);
	virtual void stopBuildBlock(Player &);
	virtual void tick();
	virtual void getPickRange(Player *, const InputMode &);
	virtual bool useItem(Player &, ItemInstance &);
	virtual bool useItemOn(Player &, ItemInstance *, const BlockPos &, signed char, const Vec3 &);
	virtual void interact(Player &, Entity &);
	virtual void attack(Player &, Entity &);
	virtual void releaseUsingItem(Player &);
	virtual void setTrialMode(bool);
	virtual void isInTrialMode();
	virtual void registerUpsellScreenCallback(std::function<void (bool)>);
};
