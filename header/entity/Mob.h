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
	Mob(BlockSource &);
	virtual void ~Mob();
	virtual void lerpTo(Vec3 const &, Vec2 const &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void getHeadHeight() const;
	virtual void isImmobile() const;
	virtual void isPickable();
	virtual void isPushable() const;
	virtual void isShootable();
	virtual void isSneaking() const;
	virtual void isAlive();
	virtual void hurt(EntityDamageSource const &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual void buildDebugInfo(std::string &) const;
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(CompoundTag const &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void _playStepSound(BlockPos const &, int);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(EntityDamageSource const &);
	virtual void resolveDeathLoot(int);
	virtual void canSee(Entity const &) const;
	virtual void onLadder(bool);
	virtual void spawnAnim();
	virtual void isSleeping() const;
	virtual void setSneaking(bool);
	virtual void isSprinting() const;
	virtual void setSprinting(bool);
	virtual void getVoicePitch();
	virtual void playAmbientSound();
	virtual void getAmbientSoundInterval();
	virtual void getItemInHandIcon(ItemInstance const *, int);
	virtual void getSpeed();
	virtual void setSpeed(float);
	virtual void getJumpPower() const;
	virtual void heal(int);
	virtual void hurtEffects(EntityDamageSource const &, int);
	virtual void getMeleeWeaponDamageBonus(Mob *);
	virtual void getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, EntityDamageSource const *);
	virtual void isInvertedHealAndHarm() const;
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual void isLookingAtAnEntity();
	virtual void canSpawn(bool);
	virtual void finalizeMobSpawn();
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual void isBaby() const;
	virtual void getCarriedItem();
	virtual void setCarriedItem(ItemInstance const &);
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual void getMaxHeadXRot();
	virtual void getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual void getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player *);
	virtual void getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual void getTarget();
	virtual void setTarget(Mob *);
	virtual void canAttack(Mob *, bool);
	virtual void isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual void performRangedAttack(Mob &, float);
	virtual void canBeControlledByRider();
	virtual void teleportTo(Vec3 const &);
	virtual void getMutableAttribute(Attribute const &);
	virtual void getAttribute(Attribute const &) const;
	virtual void getEquipmentCount() const;
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage();
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const *);
	virtual void getArmor(ArmorSlot) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getArmorTypeHash();
	virtual void dropHeldItem();
	virtual void dropAllArmor();
	virtual void dropAllGear(int);
	virtual void drop(ItemInstance const *, bool);
	virtual void sendInventory() const;
	virtual void canBeAffected(MobEffectInstance const &);
	virtual void _removeWhenFarAway();
	virtual void getDeathLoot();
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity &);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual void _getSoundVolume();
	virtual void _getAmbientSound();
	virtual void _getHurtSound();
	virtual void _getDeathSound();
	virtual void getDamageAfterArmorAbsorb(EntityDamageSource const &, int);
	virtual void getDamageAfterMagicAbsorb(EntityDamageSource const &, int);
	virtual void getExperienceReward() const;
	virtual void useNewAi();
	virtual void onEffectAdded(MobEffectInstance &);
	virtual void onEffectUpdated(MobEffectInstance const &);
	virtual void onEffectRemoved(MobEffectInstance &);
	virtual void registerAttributes();
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
