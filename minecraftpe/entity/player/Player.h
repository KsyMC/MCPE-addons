#pragma once

#include <memory>
#include "Abilities.h"
#include "../Mob.h"
#include "../item/ItemEntity.h"
#include "../../item/ItemInstance.h"
#include "../../../raknet/RakNetTypes.h"

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
class BatchPacket;
class SimpleFoodData;

// Size : 3444
class Player : public Mob
{
public:
	static float DEFAULT_WALK_SPEED;
	static float DEFAULT_FLY_SPEED;

public:
	char filler1[2];				// 3178
	int score;						// 3180
	char filler2[8];				// 3184
	std::string playerName;			// 3192
	Abilities abilities;			// 3196
	SimpleFoodData *simpleFoodData;	// 3204
	char filler3[8];				// 3208
	RakNet::RakNetGUID rakNetGUID;	// 3216
	char filler4[28];				// 3228
	Inventory *inventory;			// 3256
	char filler5[12];				// 3260
	TileSource *tileSource;			// 3272
	char filler6[40];				// 3276
	SkinInfo *skinInfo;				// 3316
	char filler7[4];				// 3320
	ItemInstance itemInstance;		// 3324
	char filler8[4];				// 3340
	ItemInstance armors[4];			// 3348
	char filler9[8];				// 3412
	PacketSender *packetSender;		// 3420
	BatchPacket *batchPacket;		// 3424
	int spawnPointX;				// 3428
	int spawnPointY;				// 3432
	int spawnPointZ;				// 3436
	bool sleeping;					// 3440


public:
	Player(Level &, PacketSender &, bool, const RakNet::RakNetGUID &);
	virtual ~Player();
	virtual void remove();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual bool isInWall();
	virtual float getHeadHeight() const;
	virtual bool isImmobile();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(EntityDamageSource &, int);
	virtual void handleEntityEvent(char);
	virtual void awardKillScore(Entity *, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(EntityDamageSource &);
	virtual bool isSleeping();
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual void getArmorValue();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance *getCarriedItem();
	virtual void getItemUseDuration();
	virtual void updateAi();
	virtual float getWalkingSpeedModifier();
	virtual void hurtArmor(int);
	virtual bool useNewAi();
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
