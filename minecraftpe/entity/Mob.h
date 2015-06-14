#pragma once

#include "Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class LookControl;
class MoveControl;
class JumpControl;
class BodyControl;
class Sensing;
class MobEffect;
class EntityUniqueID;

// Size : 3178
class Mob : public Entity
{
public:
	char filler1[16];			// 324
	float renderYawOffset;		// 340
	float prevRenderYawOffset;	// 344
	float rotationYawHead;		// 348
	float prevRotationYawHead;	// 352
	char filler2[8];			// 356
	int health;					// 364
	char filler3[2628];			// 368
	std::string skinPath;		// 2996
	char filler4[64];			// 3000
	LookControl *lockControl;	// 3064
	MoveControl *moveControl;	// 3068
	JumpControl *jumpControl;	// 3072
	BodyControl *bodyControl;	// 3076
	PathNavigation *navigator;	// 3080
	Sensing *sensing;			// 3084
	char filler5[90];			// 3088

public:
	Mob(Level &);
	Mob(TileSource &);
	virtual ~Mob();
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual float getHeadHeight() const;
	virtual bool isImmobile();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual void hurt(EntityDamageSource &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(char);
	virtual void causeFallDamage(float);
	virtual void setSize(float, float);
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(EntityDamageSource &);
	virtual bool canSee(Entity *);
	virtual void onLadder();
	virtual void spawnAnim();
	virtual void getTexture();
	virtual bool isSleeping();
	virtual bool isWaterMob();
	virtual void setSneaking(bool);
	virtual float getVoicePitch();
	virtual void getMobType();
	virtual void playAmbientSound();
	virtual int getAmbientSoundInterval();
	virtual void getItemInHandIcon(const ItemInstance *, int);
	virtual float getBaseSpeed() = 0;
	virtual void getJumpPower() const;
	virtual void superTick();
	virtual void heal(int);
	virtual int getMaxHealth();
	virtual void actuallyHurt(int, const EntityDamageSource &);
	virtual void getArmorValue();
	virtual bool isInvertedHealAndHarm() const;
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual void beforeRemove();
	virtual bool canSpawn();
	virtual void finalizeMobSpawn();
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual bool isBaby() const;
	virtual bool isTamable() const;
	virtual ItemInstance *getCarriedItem();
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob *getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual Entity *getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual Mob *getTarget();
	virtual void setTarget(Mob *);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(float, float, float);
	virtual bool removeWhenFarAway();
	virtual int getDeathLoot();
	virtual void dropDeathLoot();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void serverAiMobStep();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual float getWalkingSpeedModifier();
	virtual void getDamageAfterArmorAbsorb(const EntityDamageSource &, int);
	virtual void getDamageAfterMagicAbsorb(const EntityDamageSource &, int);
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	virtual bool canBeAffected(const MobEffectInstance &);
	virtual void onEffectAdded(const MobEffectInstance &);
	virtual void onEffectUpdated(const MobEffectInstance &);
	virtual void onEffectRemoved(const MobEffectInstance &);
	void _ctor();
	void _init();
	void addEffect(const MobEffectInstance &);
	void checkDespawn(Mob *);
	void checkDespawn();
	void getAllEffects();
	void getCurrentSwingDuration();
	void getEffect(MobEffect *);
	JumpControl *getJumpControl();
	LookControl *getLookControl();
	MoveControl *getMoveControl();
	PathNavigation *getNavigation();
	Sensing *getSensing();
	void getSpeed();
	void getWalkingSpeedEffect();
	void getYHeadRot();
	bool hasAnyEffects();
	bool hasEffect(MobEffect *);
	void interpolateOnly();
	void removeAllEffects();
	void removeEffect(int);
	void removeEffectNoUpdate(int);
	void removeEffectParticles();
	void setInvisible(bool);
	void setJumping(bool);
	void setSpeed(float);
	void setYHeadRot(float);
	void setYya(float);
	void tickEffects();
	void updateAttackAnim();
	void updateInvisibilityStatus();
	void updateMobId(EntityUniqueID &);
};
