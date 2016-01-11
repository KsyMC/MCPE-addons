#pragma once

#include <vector>
#include <string>
#include <memory>

#include "minecraftpe/util/Vec3.h"
#include "minecraftpe/util/Vec2.h"
#include "minecraftpe/entity/SynchedEntityData.h"
#include "minecraftpe/util/AABB.h"
#include "minecraftpe/util/Color.h"
#include "minecraftpe/entity/EntityType.h"
#include "minecraftpe/entity/EntityUniqueID.h"
#include "minecraftpe/network/Packet.h"
#include "minecraftpe/block/MaterialType.h"
#include "minecraftpe/event/EntityEvent.h"
#include "minecraftpe/entity/ArmorSlot.h"
#include "minecraftpe/entity/EntityLink.h"
#include "minecraftpe/level/dimension/DimensionId.h"

class Level;
class BlockSource;
class Player;
class EntityDamageSource;
class ItemInstance;
class CompoundTag;
class ChangeDimensionPacket;
class EntityPos;
class BlockPos;
class Dimension;

// Size : 340
class Entity
{
public:
	//void **vtable;			// 0
	bool b1;					// 4
	Vec3 pos;					// 8
	Vec3 lastPos;				// 20
	Vec3 pos1;					// 32
	Vec3 motion;				// 44
	Vec2 rotation;				// 56
	Vec2 lastRotation;			// 64
	Vec2 pos3;					// 72
	SynchedEntityData data;		// 80
	char filler1[12];			// 96
	DimensionId dimensionId;	// 108
	char filler2[4];			// 112
	Level *level;				// 116
	char filler3[4];			// 120
	Color color;				// 124
	AABB boundingBox;			// 140
	float width;				// 168
	float height;				// 172
	char filler5[16];			// 176
	Vec2 pos4;					// 192
	char filler6[16];			// 200
	short air;					// 216
	int fireTicks;				// 220
	char filler7[4];			// 224
	int portalCooldown;			// 228
	char filler8[16];			// 232
	std::vector<Entity *> rider;// 248
	char filler9[4];			// 260
	Entity *vehicle;			// 264
	char filler10[8];			// 268
	float fallDistance;			// 276
	bool b2;					// 280
	bool onGround;				// 281
	char filler11[12];			// 284
	EntityUniqueID uniqueID;	// 296
	char filler12[4];			// 304
	Vec3 pos5;					// 308
	char filler13[10];			// 320
	bool inWater;				// 330
	bool dead;					// 332
	bool global;				// 333
	BlockSource *source;		// 336

	Entity(Level &);
	Entity(BlockSource &);
	virtual ~Entity();
	virtual void _postInit();
	virtual void reset();
	virtual void getOwnerEntityType();
	virtual void remove();
	virtual void setPos(const Vec3 &);
	virtual Vec3 &getPos() const;
	virtual Vec3 &getPosOld() const;
	virtual void getPosExtrapolated(float) const;
	virtual Vec3 &getVelocity() const;
	virtual void move(const Vec3 &);
	virtual void checkBlockCollisions(const AABB &);
	virtual void checkBlockCollisions();
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void lerpMotion(const Vec3 &);
	virtual void turn(const Vec2 &);
	virtual void interpolateTurn(const Vec2 &);
	virtual std::unique_ptr<Packet> getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity &) const;
	virtual void getRidingHeight();
	virtual void getRideHeight() const;
	virtual void startRiding(Entity &);
	virtual void addRider(Entity &);
	virtual void removeRider(Entity &);
	virtual void intersects(const Vec3 &, const Vec3 &);
	virtual bool isFree(const Vec3 &, float);
	virtual bool isFree(const Vec3 &);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual void setNameTagVisible(bool);
	virtual std::string getNameTag() const;
	virtual void setNameTag(const std::string &);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius() const;
	virtual bool isSkyLit(float);
	virtual void getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player &);
	virtual void canInteractWith(Player &);
	virtual void getInteractText(Player &);
	virtual void playerTouch(Player &);
	virtual void push(Entity &, bool);
	virtual void push(const Vec3 &);
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
	virtual void hurt(const EntityDamageSource &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void handleEntityEvent(EntityEvent);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance &, float);
	virtual void awardKillScore(Entity &, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance &);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(const CompoundTag &);
	virtual void loadLinks(const CompoundTag &, std::vector<EntityLink> &);
	virtual EntityType getEntityTypeId() const = 0;
	virtual void queryEntityRenderer();
	virtual EntityUniqueID getSourceUniqueID();
	virtual void setOnFire(int);
	virtual void getHandleWaterAABB() const;
	virtual void handleInsidePortal();
	virtual void getPortalCooldown() const;
	virtual void getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket &);
	virtual EntityUniqueID getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSound(const std::string &, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity &) const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool);
	virtual void buildDebugInfo(std::string &) const;
	virtual void setSize(float, float);
	virtual void setPos(const EntityPos &);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag &) = 0;
	virtual void addAdditionalSaveData(CompoundTag &) = 0;
	virtual void _playStepSound(const BlockPos &, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(const Vec3 &);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	float distanceTo(const Vec3 &);
	bool isRiding() const;
	BlockSource *getRegion() const;
	void moveTo(const Vec3 &, const Vec2 &);
	void setRot(const Vec2 &);
	Vec2 getRotation() const;
	EntityUniqueID &getUniqueID() const;
	void setUniqueID(EntityUniqueID);
	Dimension *getDimension() const;
};
