#pragma once

#include "minecraftpe/entity/Mob.h"
#include "minecraftpe/gamemode/GameType.h"
#include "minecraftpe/util/UUID.h"
#include "minecraftpe/entity/player/Abilities.h"
#include "minecraftpe/network/Packet.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/block/BlockPos.h"
#include "raknet/RakNetTypes.h"

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

	int i1;								// 3280
	bool b4;							// 3284
	int score;							// 3288
	char filler2[12];					// 3292
	std::string username;				// 3304
	Abilities abilities;				// 3308
	BaseContainerMenu *activeContainer;	// 3324
	RakNet::RakNetGUID guid;			// 3328
	std::string what;					// 3344
	char filler4[4];					// 3348
	long long clientId;					// 3352
	mce::UUID uuid;						// 3360
	char filler5[20];					// 3376
	PlayerChunkSource *chunk1;			// 3396
	PlayerChunkSource *chunk2;			// 3400
	BlockSource *region;				// 3404
	BlockPos bedPos;					// 3408
	char filler6[28];					// 3420
	Inventory *inventory;				// 3448
	SkinInfoData *skin;					// 3452
	char filler7[4];					// 3456
	DimensionId respawnDimensionId;		// 3460
	bool b2;							// 3464
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

	Player(Level &, PacketSender &, GameType, const RakNet::RakNetGUID &, std::unique_ptr<SkinInfoData>, mce::UUID);
	virtual ~Player();
	virtual void remove();
	virtual std::unique_ptr<Packet> getAddPacket();
	virtual void normalTick();
	virtual void rideTick();
	virtual void getRidingHeight();
	virtual bool isInWall();
	virtual bool isImmobile() const;
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(const EntityDamageSource &, int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void awardKillScore(Entity &, int);
	virtual EntityType getEntityTypeId() const;
	virtual void getPortalCooldown() const;
	virtual void getPortalWaitTime() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void die(const EntityDamageSource &);
	virtual bool isSleeping() const;
	virtual void getSpeed();
	virtual void setSpeed(float);
	virtual void travel(float, float);
	virtual void aiStep();
	virtual ItemInstance *getCarriedItem();
	virtual void getItemUseDuration();
	virtual void dropAllGear(int);
	virtual void drop(const ItemInstance *, bool);
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
	virtual void tickWorld(const Tick &);
	virtual void moveView();
	virtual void setName(const std::string &);
	virtual void _checkMovementStatistiscs(const Vec3 &);
	virtual void respawn();
	virtual bool isInTrialMode();
	virtual void hasResource(int);
	virtual void completeUsingItem();
	virtual void drop(const ItemInstance *);
	virtual void startCrafting(int, const BlockPos &);
	virtual void startStonecutting(const BlockPos &);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(int, const BlockPos &);
	virtual void openFurnace(int, const BlockPos &);
	virtual void openEnchanter(int, const BlockPos &);
	virtual void openAnvil(const BlockPos &);
	virtual void openBrewingStand(int, const BlockPos &);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	virtual void startSleepInBed(const BlockPos &);
	virtual void stopSleepInBed(bool, bool);
	virtual void getSleepTimer();
	virtual void openTextEdit(BlockEntity *);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void setPlayerGameTypePacketReceived(GameType);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Entity &);
	virtual void getTelemetry() const;
	virtual void sendTelemetryPacket(const TelemetryEventPacket &);
	virtual void closeContainer();
	virtual void onMovePlayerPacketNormal(const Vec3 &, const Vec2 &);
	static bool isValidUserName(const std::string &);
	ItemInstance *getSelectedItem() const;
	bool IsCreative() const;
	bool IsSurvival() const;
	bool IsViewer() const;
	Dimension *getDimension() const;
	bool hasRespawnPosition() const;
	BlockPos getSpawnPosition();
	void setRespawnPosition(const BlockPos &);
	void setSkin(bool, bool, const std::string &);
	void take(Entity &, int);
};
