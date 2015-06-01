#pragma once

#include "..\Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class MobEffect;
class EntityUniqueID;

// Size : 3178
class Mob : public Entity
{
public:
	char filler1[42];		// 324
	int health;				// 328
	char filler2[2672];		// 324
	std::string skinPath;	// 2996

public:
	Mob(Level &);
	Mob(TileSource &);
	virtual ~Mob();
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void getHeadHeight() const;
	virtual void isImmobile();
	virtual void isPickable();
	virtual void isPushable();
	virtual void isShootable();
	virtual void isSneaking();
	virtual void isAlive();
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
	virtual void canSee(Entity *);
	virtual void onLadder();
	virtual void spawnAnim();
	virtual void getTexture();
	virtual void isSleeping();
	virtual void isWaterMob();
	virtual void setSneaking(bool);
	virtual void getVoicePitch();
	virtual void getMobType();
	virtual void playAmbientSound();
	virtual void getAmbientSoundInterval();
	virtual void getItemInHandIcon(const ItemInstance *, int);
	virtual float getBaseSpeed() = 0;
	virtual void getJumpPower() const;
	virtual void superTick();
	virtual void heal(int);
	virtual void getMaxHealth();
	virtual void actuallyHurt(int, const EntityDamageSource &);
	virtual void getArmorValue();
	virtual void isInvertedHealAndHarm() const;
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual void isLookingAtAnEntity();
	virtual void beforeRemove();
	virtual void canSpawn();
	virtual void finalizeMobSpawn();
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual void isBaby() const;
	virtual void isTamable() const;
	virtual void getCarriedItem();
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual void getMaxHeadXRot();
	virtual void getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual void getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual void getTarget();
	virtual void setTarget(Mob *);
	virtual void isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual void canBeControlledByRider();
	virtual void teleportTo(float, float, float);
	virtual void removeWhenFarAway();
	virtual void getDeathLoot();
	virtual void dropDeathLoot();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void serverAiMobStep();
	virtual void getSoundVolume();
	virtual void getAmbientSound();
	virtual void getHurtSound();
	virtual void getDeathSound();
	virtual void getWalkingSpeedModifier();
	virtual void getDamageAfterArmorAbsorb(const EntityDamageSource &, int);
	virtual void getDamageAfterMagicAbsorb(const EntityDamageSource &, int);
	virtual void hurtArmor(int);
	virtual void useNewAi();
	virtual void canBeAffected(const MobEffectInstance &);
	virtual void onEffectAdded(const MobEffectInstance &);
	virtual void onEffectUpdated(const MobEffectInstance &);
	virtual void onEffectRemoved(const MobEffectInstance &);
	void _ctor();
	void _init();
	void addEffect(const MobEffectInstance &);
	bool canShowNameTag();
	void getAllEffect();
	void getCurrentSwingDuration();
	void getItemUseDuration();
	void getJumpControl();
	void getMobType();
	void *getMoveControl();
	PathNavigation *getNavigation();
	bool getSensing();
	float getSpeed();
	float getWalkingSpeedEffect();
	float getYHeadRot();
	bool hasAnyEffects();
	bool hasEffect(MobEffect *);
	bool interpolateOnly();
	bool isInvisible();
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
