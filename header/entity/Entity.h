#pragma once

#include <string>
#include <vector>
#include "SynchedEntityData.h"
#include "../util/AABB.h"

class Level;
class BlockSource;
class Random;
class Vec3;
class Material;
class Player;
class EntityDamageSource;
class CompoundTag;
class ItemInstance;
class EntityPos;
class EntityLink;
class BlockPos;
class Vec2;
class EntityUniqueID;

// Size : 324
class Entity
{
public:
	static std::string RIDING_TAG;
	static int TOTAL_AIR_SUPPLY;
	static uint mEntityCounter;

public:
	// void **vtable;
	char filler1[4];			// 4
	SynchedEntityData data;		// 8
	float posX;					// 24
	float posY;					// 28
	float posZ;					// 32
	char filler2[12];			// 36
	BlockSource *blockSource;	// 48
	char filler3[4];			// 52
	Level *level;				// 56
	float prevPosX;				// 60
	float prevPosY;				// 64
	float prevPosZ;				// 68
	float motionX;				// 72
	float motionY;				// 76
	float motionZ;				// 80
	float rotationYaw;			// 84
	float rotationPitch;		// 88
	float prevRotationPitch;	// 92
	float prevRotationYaw;		// 96
	char filler4[40];			// 100
	AABB boundingBox;			// 140
	char filler5[4];			// 168
	float width;				// 172
	float height;				// 176
	char filler6[32];			// 180
	int ticksExisted;			// 212
	char filler7[8];			// 216
	int fireResistance;			// 224
	char filler8[4];			// 228
	int entityRendererId;		// 232
	std::vector<Entity *> riddenByEntities;	// 236
	char filler9[4];			// 248
	Entity *ridingEntity;		// 252
	char filler10[48];			// 256
	bool inWater;				// 304
	char filler11[16];			// 308

public:
	Entity(Level &);
	Entity(BlockSource &);
	virtual ~Entity();
	virtual void _postInit();
	virtual void reset();
	virtual void getOwnerEntityType();
	virtual void remove();
	virtual void setPos(Vec3 const &);
	virtual void getPos() const;
	virtual void getPosOld() const;
	virtual void getPosExtrapolated(float) const;
	virtual void getVelocity() const;
	virtual void move(Vec3 const &);
	virtual void checkBlockCollisions(AABB const &);
	virtual void checkBlockCollisions();
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(Vec3 const &, Vec2 const &, int);
	virtual void lerpMotion(Vec3 const &);
	virtual void turn(Vec2 const &);
	virtual void interpolateTurn(Vec2 const &);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity &) const;
	virtual void getRidingHeight();
	virtual void getRideHeight() const;
	virtual void startRiding(Entity &);
	virtual void addRider(Entity &);
	virtual void removeRider(Entity &);
	virtual void intersects(Vec3 const &, Vec3 const &);
	virtual bool isFree(Vec3 const &, float);
	virtual bool isFree(Vec3 const &);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual void canShowNameTag();
	virtual void setNameTagVisible(bool);
	virtual void getNameTag() const;
	virtual void setNameTag(std::string const &);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual void makeStuckInWeb();
	virtual void getHeadHeight() const;
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius() const;
	virtual bool isSkyLit(float);
	virtual void getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player &);
	virtual bool canInteractWith(Player &);
	virtual void getInteractText(Player &);
	virtual void playerTouch(Player &);
	virtual void push(Entity &, bool);
	virtual void push(Vec3 const &);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void shouldRenderAtSqrDistance(float);
	virtual void hurt(EntityDamageSource const &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void handleEntityEvent(EntityEvent);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(ItemInstance const &, float);
	virtual void awardKillScore(Entity &, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, ItemInstance const &);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(CompoundTag const &);
	virtual void loadLinks(CompoundTag const &, std::vector<EntityLink> &);
	virtual void getEntityTypeId() const = 0;
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID();
	virtual void setOnFire(int);
	virtual void getHandleWaterAABB() const;
	virtual void handleInsidePortal();
	virtual void getPortalCooldown() const;
	virtual void getPortalWaitTime() const;
	virtual void getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket &);
	virtual void getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSound(std::string const &, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual void canAddRider(Entity &) const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool);
	virtual void buildDebugInfo(std::string &) const;
	virtual void setSize(float, float);
	virtual void setPos(EntityPos const &);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag const &) = 0;
	virtual void addAdditionalSaveData(CompoundTag &) = 0;
	virtual void _playStepSound(BlockPos const &, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vec3 const &);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	void _findRider(Entity &) const;
	void _init();
	void _manageRiders(BlockSource &);
	void _sendLinkPacket(const EntityLink &) const;
	void _tryPlaceAt(const Vec3 &);
	void _updateOwnerChunk();
	void checkTileCollisions();
	void distanceSqrToBlockPosCenter(const BlockPos &);
	void distanceTo(Entity *);
	void distanceTo(float, float, float);
	void distanceToSqr(Entity *);
	void distanceToSqr(float, float, float);
	void enableAutoSendPosRot(bool);
	void getCenter(float);
	void getInterpolatedPosition(float) const;
	void getInterpolatedPosition2(float) const;
	void getInterpolatedRotation(float) const;
	void getLinks() const;
	void getRandomPointInAABB(Random &);
	Vec2 &getRotation() const;
	void getStatusFlag(int) const;
	void getStatusFlag(int, bool);
	void getUniqueID() const;
	void getViewVector(float) const;
	void getViewVector2(float) const;
	bool hasUniqueID() const;
	bool isControlledByLocalInstance() const;
	bool isInClouds() const;
	bool isInstanceOf(int) const;
	bool isMob() const;
	bool isRide() const;
	bool isRider(Entity &) const;
	bool isRiding() const;
	void moveTo(const Vec3 &, const Vec2 &);
	bool operator==(Entity &);
	void removeAllRiders();
	void saveLinks() const;
	void sendMotionPacketIfNeeded();
	void sendMotionToServer();
	void setOnFire(int);
	void setRegion(BlockSource &);
	void setUniqueID(EntityUniqueID);
	void shouldRender();
};
