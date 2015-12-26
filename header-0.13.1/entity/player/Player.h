#pragma once

#include "minecraftpe/entity/Mob.h"
#include "minecraftpe/gamemode/GameType.h"
#include "minecraftpe/util/UUID.h"
#include "minecraftpe/entity/player/Abilities.h"
#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/block/BlockPos.h"

class Level;
class BaseContainerMenu;
class PlayerChunkSource;
class Inventory;
class SkinInfoData;
class PacketSender;
class BatchPacket;
class ChunkSource;
class Tick;
class BlockEntity;
class EntityDamageSource;
class TelemetryEventPacket;
class CompoundTag;

// Size : 3564
class Player : public Mob
{
public:
	static Attribute EXHAUSTION;
	static Attribute EXPERIENCE;
	static Attribute HUNGER;
	static Attribute LEVEL;
	static Attribute SATURATION;

	char filler1[8];					// 3280
	int score;							// 3288
	char filler2[12];					// 3292
	string username;					// 3304
	Abilities abilities;				// 3308
	BaseContainerMenu *activeContainer;	// 3324
	RakNet::RakNetGUID guid;			// 3328
	string what;						// 3344
	char filler4[4];					// 3348
	long long clientId;					// 3352
	mce::UUID uuid;						// 3360
	char filler5[20];					// 3376
	PlayerChunkSource *chunk1;			// 3396
	PlayerChunkSource *chunk2;			// 3400
	BlockSource *region;				// 3404
	char filler6[40];					// 3408
	Inventory *inventory;				// 3448
	SkinInfoData *skin;					// 3452
	char filler7[4];					// 3456
	DimensionId respawnDimensionId;		// 3460
	bool b1;							// 3464
	ItemInstance usingItem;				// 3468
	char filler8[8];					// 3488
	int viewDistance;					// 3496
	PacketSender *packetSender;			// 3500
	BatchPacket *batchPacket;			// 3504
	char filler9[16];					// 3508
	BlockPos spawnPos;					// 3524
	char filler10[16];					// 3536
	bool destroying;					// 3552
	GameType gameType;					// 3556
	char filler11[4];					// 3560

	Player(Level &, PacketSender &, GameType, RakNet::RakNetGUID const &, unique_ptr<SkinInfoData>, mce::UUID);
	virtual ~Player();
	virtual void remove();
	virtual unique_ptr<Packet> getAddPacket();
	virtual void normalTick();
	virtual void rideTick();
	virtual void getRidingHeight();
	virtual bool isInWall();
	virtual bool isImmobile() const;
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(EntityDamageSource const &, int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void awardKillScore(Entity &, int);
	virtual int getEntityTypeId() const;
	virtual void getPortalCooldown() const;
	virtual void getPortalWaitTime() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag const &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void die(EntityDamageSource const &);
	virtual bool isSleeping() const;
	virtual void getSpeed();
	virtual void setSpeed(float);
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance *getCarriedItem();
	virtual void getItemUseDuration();
	virtual void dropAllGear(int);
	virtual void drop(ItemInstance const *, bool);
	virtual void sendInventory() const;
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void getExperienceReward() const;
	virtual bool useNewAi();
	virtual void registerAttributes();
	virtual void prepareRegion(ChunkSource &);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void onPrepChangeDimension();
	virtual void onDimensionChanged();
	virtual void tickWorld(Tick const &);
	virtual void moveView();
	virtual void setName(string const &);
	virtual void _checkMovementStatistiscs(Vec3 const &);
	virtual void respawn();
	virtual bool isInTrialMode();
	virtual void hasResource(int);
	virtual void completeUsingItem();
	virtual void drop(ItemInstance const *);
	virtual void startCrafting(int, BlockPos const &);
	virtual void startStonecutting(BlockPos const &);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(int, BlockPos const &);
	virtual void openFurnace(int, BlockPos const &);
	virtual void openEnchanter(int, BlockPos const &);
	virtual void openAnvil(BlockPos const &);
	virtual void openBrewingStand(int, BlockPos const &);
	virtual void displayChatMessage(string const &, string const &);
	virtual void displayClientMessage(string const &);
	virtual void displayLocalizableMessage(string const &, vector<string> const &);
	virtual void startSleepInBed(BlockPos const &);
	virtual void stopSleepInBed(bool, bool);
	virtual void getSleepTimer();
	virtual void openTextEdit(BlockEntity *);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void setPlayerGameTypePacketReceived(GameType);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Entity &);
	virtual void getTelemetry() const;
	virtual void sendTelemetryPacket(TelemetryEventPacket const &);
	virtual void closeContainer();
	virtual void onMovePlayerPacketNormal(Vec3 const &, Vec2 const &);
	static bool isValidUserName(string const &);
	ItemInstance *getSelectedItem() const;
	bool IsCreative() const;
	bool IsSurvival() const;
	bool IsViewer() const;
	Dimension *getDimension() const;
	bool hasRespawnPosition() const;
	BlockPos getSpawnPosition();
	void setRespawnPosition(BlockPos const &);
	void setSkin(bool, bool, string const &);
};
