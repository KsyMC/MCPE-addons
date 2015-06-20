#pragma once

#include <string>
#include <vector>
#include "SynchedEntityData.h"
#include "../util/AABB.h"

class Level;
class TileSource;
class Random;
class Vec3;
class Material;
class Player;
class EntityDamageSource;
class CompoundTag;
class ItemInstance;
class EntityPos;
class EntityLink;
class TilePos;
class Vec2;
class EntityUniqueID;

// Size : 324
class Entity
{
public:
	static std::string RIDING_TAG;
	static uint entityCounter;
	static Random *sharedRandom;

public:
	// void **vtable;
	char filler1[4];			// 4
	SynchedEntityData data;		// 8
	float posX;					// 24
	float posY;					// 28
	float posZ;					// 32
	char filler2[12];			// 36
	TileSource *tileSource;		// 48
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
	Entity(Level &, bool);
	Entity(TileSource &, bool);
	virtual ~Entity();
	virtual void reset();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual Vec3 &getPos() const;
	virtual Vec3 &getPosOld() const;
	virtual void getPosExtrapolated(float) const;
	virtual Vec3 &getVelocity() const;
	virtual void setRot(float, float);
	virtual void move(float, float, float);
	virtual void moveTo(float, float, float, float, float);
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void lerpMotion(float, float, float);
	virtual void turn(float, float);
	virtual void interpolateTurn(float, float);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity &) const;
	virtual float getRidingHeight();
	virtual float getRideHeight() const;
	virtual int getRideUseAnimation() const;
	virtual void startRiding(Entity &);
	virtual void addRider(Entity &);
	virtual void removeRider(Entity &);
	virtual void intersects(float, float, float, float, float, float);
	virtual bool isFree(float, float, float, float);
	virtual bool isFree(float, float, float);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual void getNameTag();
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(const Material *) const;
	virtual float getShadowRadius() const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual void getShadowHeightOffs();
	virtual bool isSkyLit(float);
	virtual void getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player *);
	virtual bool canInteractWith(Player *);
	virtual std::string getInteractText(Player *);
	virtual void playerTouch(Player *);
	virtual void push(Entity *);
	virtual void push(float, float, float);
	virtual bool isImmobile();
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void shouldRenderAtSqrDistance(float);
	virtual void hurt(EntityDamageSource &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(char);
	virtual float getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance &, float);
	virtual void awardKillScore(Entity *, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(const CompoundTag &);
	virtual void loadLinks(const CompoundTag &, std::vector<EntityLink> &);
	virtual int getEntityTypeId() const;
	virtual void queryEntityRenderer();
	virtual bool isItemEntity();
	virtual bool isHangingEntity();
	virtual void getOwnerID();
	virtual void getHandleWaterAABB() const;
	virtual void getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void setSize(float, float);
	virtual void setPos(EntityPos *);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag *) = 0;
	virtual void addAdditionalSaveData(CompoundTag *) = 0;
	virtual void playStepSound(int, int, int, int);
	virtual void checkInsideTiles(float);
	virtual void onTileCollision(int);
	virtual void playSound(const std::string &, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity &) const;
	virtual void stopRiding(bool);
	void _findRider(Entity &) const;
	void _init() ;
	void _manageRiders(TileSource &);
	void _sendLinkPacket(const EntityLink &) const;
	void _tryPlaceAt(const Vec3 &) ;
	void _updateOwnerChunk();
	void checkTileCollisions();
	void distanceSqrToBlockPosCenter(const TilePos &);
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
	void setRegion(TileSource &);
	void setUniqueID(EntityUniqueID);
	void shouldRender();
};
