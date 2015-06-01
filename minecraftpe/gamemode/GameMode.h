#pragma once

class PacketSender;
class Level;
class Vibration;
class Player;
class ItemInstance;
class TilePos;
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
	virtual ~GameMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void continueDestroyBlock(Player*, int, int, int, signed char) = 0;
	virtual void stopDestroyBlock(Player *);
	virtual void tick();
	virtual void getPickRange();
	virtual void useItem(Player &, ItemInstance &);
	virtual void useItemOn(Player &, ItemInstance *, TilePos const&, signed char, const Vec3 &);
	virtual void initPlayer(Player*);
	virtual void canHurtPlayer();
	virtual void interact(Player *, Entity *);
	virtual void attack(Player *, Entity *);
	virtual void handleInventoryMouseClick(int, int, int, Player *);
	virtual void handleCloseInventory(int, Player *);
	virtual void isCreativeType();
	virtual void isSurvivalType();
	virtual void initAbilities(Abilities &);
	virtual void releaseUsingItem(Player *);
};
