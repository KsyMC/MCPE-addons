#pragma once

#include <string>
#include <vector>

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

// Size : 324
class Entity
{
public:
	static std::string RIDING_TAG;
	static uint entityCounter;
	static Random *sharedRandom;

public:
	// void **vtable;
	char filler1[28];			// 4
	float x;					// 24
	float y;					// 28
	float z;					// 32
	char filler2[4];			// 44
	TileSource *tileSource;		// 48
	char filler3[32];			// 52
	float yaw;					// 84
	char filler4[144];			// 88
	int entityRendererId;		// 232
	char filler5[49];			// 236
	bool b1;					// 285

public:
	Entity(Level &);
	Entity(TileSource &);
	virtual ~Entity();
	virtual void reset();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual void getPos() const;
	virtual void getPosOld() const;
	virtual void getPosExtrapolated(float) const;
	virtual void getVelocity() const;
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
	virtual void getRidingHeight();
	virtual void getRideHeight() const;
	virtual void getRideUseAnimation() const;
	virtual void startRiding(Entity &);
	virtual void addRider(Entity &);
	virtual void removeRider(Entity &);
	virtual void intersects(float, float, float, float, float, float);
	virtual void isFree(float, float, float, float);
	virtual void isFree(float, float, float);
	virtual void isInWall();
	virtual void isInvisible();
	virtual void canShowNameTag();
	virtual void getNameTag();
	virtual void isInWater() const;
	virtual void isInWaterOrRain();
	virtual void isInLava();
	virtual void isUnderLiquid(const Material *) const;
	virtual void getShadowRadius() const;
	virtual void makeStuckInWeb();
	virtual void getHeadHeight() const;
	virtual void getShadowHeightOffs();
	virtual void isSkyLit(float);
	virtual void getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player *);
	virtual void canInteractWith(Player *);
	virtual void getInteractText(Player *);
	virtual void playerTouch(Player *);
	virtual void push(Entity *);
	virtual void push(float, float, float);
	virtual void isImmobile();
	virtual void isSilent();
	virtual void isPickable();
	virtual void isPushable();
	virtual void isShootable();
	virtual void isSneaking();
	virtual void isAlive();
	virtual void isOnFire() const;
	virtual void isCreativeModeAllowed();
	virtual void isSurfaceMob() const;
	virtual void shouldRenderAtSqrDistance(float);
	virtual void hurt(EntityDamageSource &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(char);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance &, float);
	virtual void awardKillScore(Entity *, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(const CompoundTag &);
	virtual void loadLinks(const CompoundTag &, std::vector<EntityLink> &);
	virtual void getEntityTypeId() const;
	virtual void queryEntityRenderer();
	virtual void isItemEntity();
	virtual void isHangingEntity();
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
	virtual void canAddRider(Entity &) const;
	virtual void stopRiding(bool);
	void _findRider(Entity &);
	void _init();
	void _manageRiders(TileSource &);
	void _sendLinkPacket(const EntityLink &);
	void _tryPlaceAt(const Vec3 &);
	void _updateOwnerChunk();
	float distanceSqrToBlockPosCenter(const TilePos &);
	float distanceTo(Entity *);
	float distanceToSqr(float, float, float);
	void enableAutoSendPosRot(bool);
	void exitRide(const Entity &, float);
	void getCenter(float);
	void getInterpolatedPosition(float);
	void getInterpolatedPosition2(float);
	void getInterpolatedRotation(float);
	void getLinks();
	void getRandomPointInAABB(Random &);
	float getRotation();
	bool getSharedFlag(int);
	void getUniqueID();
	void getViewVector(float);
	bool hasUniqueID();
	bool isControlledByLocalInstance();
	bool isInClouds() const;
	bool isInstanceOf(int);
	bool isMob() const;
	bool isRide() const;
	bool isRider(Entity &) const;
	void markHunt();
	void moveTo(const Vec3 &, const Vec2 &);
	bool operator==(Entity &);
	void removeAllRiders();
	void saveLinks();
	void saveWitchoutId(CompoundTag &);
	void sendMotionPacketIfNeeded();
	void sendMotionToServer();
	void setOnFire(int);
	void setRegion(TileSource &);
	void setRot(const Vec2 &);
	void setSharedFlag(int, bool);
	void setUniqueID(int, bool);
	void shouldRender();
};
