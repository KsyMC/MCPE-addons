#pragma once

#include <memory>
#include "..\Mob.h"
#include "..\..\Abilities.h"
#include "..\item\ItemEntity.h"
#include "..\..\..\raknet\RakNetTypes.h"

class PacketSender;
class Inventory;
class SkinInfo;
class Tick;
class ChestTileEntity;
class FurnaceTileEntity;
class TileEntity;
class Packet;
class LevelChunk;
class Tile;
class ChunkSource;

// Size : 3432
class Player : public Mob
{
public:
	static float DEFAULT_WALK_SPEED;
	static float DEFAULT_FLY_SPEED;

public:
	char filler1[2832];				// 332
	std::string playerName;			// 3164
	char filler2[16];				// 3168
	Abilities abilities;			// 3196
	char filler3[12];				// 3200
	Inventory *inventory;			// 3244
	char filler4[180];				// 3216
	SkinInfo *skinInfo;				// 3304
	RakNet::RakNetGUID rakNetGUID;	// 3336
	PacketSender *packetSender;		// 3408

public:
	Player(Level &, PacketSender &, bool, const RakNet::RakNetGUID &);
	virtual ~Player();
	virtual void remove();
	virtual void normalTick();
	virtual void rideTick();
	virtual void getRidingHeight();
	virtual void isInWall();
	virtual void getHeadHeight() const;
	virtual void isImmobile();
	virtual void isPushable();
	virtual void isShootable();
	virtual void isCreativeModeAllowed();
	virtual void hurt(EntityDamageSource &, int);
	virtual void handleEntityEvent(char);
	virtual void awardKillScore(Entity *, int);
	virtual void getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(EntityDamageSource &);
	virtual void isSleeping();
	virtual void getBaseSpeed();
	virtual void getMaxHealth();
	virtual void getArmorValue();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual void getCarriedItem();
	virtual void getItemUseDuration();
	virtual void updateAi();
	virtual void getWalkingSpeedModifier();
	virtual void hurtArmor(int);
	virtual void useNewAi();
	virtual void tickWorld(const Tick &);
	virtual void moveView();
	virtual void setName(const std::string &);
	virtual void respawn();
	virtual void hasResource(int);
	virtual void completeUsingItem();
	virtual void drop(const ItemInstance *);
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int);
	virtual void startStonecutting(int, int, int);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void getSleepTimer();
	virtual void openTextEdit(TileEntity *);
	virtual void isLocalPlayer();
	virtual void stopLoading();
	virtual void closeContainer();
	void _init();
	void addBatchPacket(Packet *);
	void animateRespawn(Player *, Level *);
	void attack(Entity *);
	bool canUseCarriedItemWhileMoving();
	bool checkBed();
	bool checkSpawnPosition(LevelChunk &);
	void destroyRegin();
	void getArmor(int);
	std::string getArmorTypeHash();
	float getDestroySpeed(Tile *);
	void getItemInUse();
	void getItemInUseDuration();
	int getLoadedChunksCount();
	int getScore();
	ItemInstance *getSelectedItem();
	SkinInfo *getSkin() const;
	float getSleepRotation();
	void *getSpawnPosition();
	void *getStandingPositionOnBlock(const TilePos &);
	void *getTicksUsingItem();
	float getViewRadius() const;
	void *hasRespawnPosition() const;
	void interact(Entity *);
	bool isHurt();
	bool isSleepingLongEnough();
	bool isUsingItem();
	void prepareRegion(ChunkSource &);
	void reallyDrop(std::unique_ptr<ItemEntity>);
	bool recheckSpawnPosition();
	void releaseUsingItem();
	void resetPos(bool);
	void sendInventory();
	void setAllPlayersSleeping();
	void setArmor(int, const ItemInstance *);
	void setBedOffset(int);
	void setDefaultHeadHeight();
	void setRespawnPosition(const TilePos &);
	void setSkin(bool, const std::string &);
	void settTeleportDestPos(const Vec3 &);
	void spawnEatParticles(const ItemInstance *, int);
	void stopUsingItem();
	void take(Entity *, int);
	void tileEntityDestroyed(int);
	void touch(Entity *);
	void updateTeleportDestPos();
	void useItem(ItemInstance &);
};
