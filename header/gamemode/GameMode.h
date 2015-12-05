#pragma once

#include <functional>

class PacketSender;
class Level;
class Vibration;
class Player;
class ItemInstance;
class BlockPos;
class Vec3;
class Entity;
class Abilities;

// Size : 32
class GameMode
{
public:
	//void **vtable;				// 0
	char filler1[8];				// 4
	PacketSender *packetSender;		// 12
	Level *level;					// 16
	char filler1[12];				// 20

public:
	GameMode(PacketSender &, Level &, Vibration &);
	virtual void ~GameMode();
	virtual void startDestroyBlock(Player &, BlockPos, signed char);
	virtual void destroyBlock(Player &, BlockPos, signed char);
	virtual void continueDestroyBlock(Player &, BlockPos, signed char);
	virtual void stopDestroyBlock(Player &);
	virtual void startBuildBlock(Player &, BlockPos, signed char);
	virtual void buildBlock(Player &, BlockPos, signed char);
	virtual void continueBuildBlock(Player &, BlockPos, signed char);
	virtual void stopBuildBlock(Player &);
	virtual void tick();
	virtual void getPickRange(Player *, InputMode const &);
	virtual void useItem(Player &, ItemInstance &);
	virtual void useItemOn(Player &, ItemInstance *, BlockPos const &, signed char, Vec3 const &);
	virtual void interact(Player &, Entity &);
	virtual void attack(Player &, Entity &);
	virtual void releaseUsingItem(Player &);
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode();
	virtual void registerUpsellScreenCallback(std::function<void (bool)>);
};
