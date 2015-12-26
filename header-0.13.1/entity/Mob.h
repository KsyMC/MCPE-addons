#pragma once

#include "minecraftpe/entity/Entity.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/mobeffect/MobEffectInstance.h"
#include "minecraftpe/entity/attribute/Attribute.h"
#include "minecraftpe/event/EntityEvent.h"
#include "minecraftpe/entity/ArmorSlot.h"

class Level;
class BlockSource;
class Vec3;
class Vec2;
class EntityDamageSource;
class BaseAttributeMap;
class Attribute;
class CompoundTag;
class ItemEntity;
class BlockPos;
class Player;

// Size : 3280
class Mob : public Entity
{
public:
	char filler1[2604];						// 340
	ItemInstance helmet;					// 2944
	ItemInstance chestplate;				// 2964
	ItemInstance leggings;					// 2984
	ItemInstance boots;						// 3004
	BaseAttributeMap *attributeMap;			// 3024
	vector<MobEffectInstance> effects;		// 3028
	char filler2[240];						// 3040

	Mob(Level &);
	Mob(BlockSource &);
	virtual ~Mob();
	virtual void lerpTo(Vec3 const &, Vec2 const &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void getHeadHeight() const;
	virtual bool isImmobile() const;
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive();
	virtual void hurt(EntityDamageSource const &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual void buildDebugInfo(string &) const;
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(CompoundTag const &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void _playStepSound(BlockPos const &, int);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(EntityDamageSource const &);
	virtual void resolveDeathLoot(int);
	virtual bool canSee(Entity const &) const;
	virtual void onLadder(bool);
	virtual void spawnAnim();
	virtual bool isSleeping() const;
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
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
	virtual bool isInvertedHealAndHarm() const;
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual void canSpawn(bool);
	virtual void finalizeMobSpawn();
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual bool isBaby() const;
	virtual ItemInstance *getCarriedItem();
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
	virtual bool canAttack(Mob *, bool);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual void performRangedAttack(Mob &, float);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(Vec3 const &);
	virtual void getMutableAttribute(Attribute const &);
	virtual void getAttribute(Attribute const &) const;
	virtual int getEquipmentCount() const;
	virtual void getArmorValue();
	virtual float getArmorCoverPercentage();
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const *);
	virtual ItemInstance *getArmor(ArmorSlot) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getArmorTypeHash();
	virtual void dropHeldItem();
	virtual void dropAllArmor();
	virtual void dropAllGear(int);
	virtual void drop(ItemInstance const *, bool);
	virtual void sendInventory() const;
	virtual bool canBeAffected(MobEffectInstance const &);
	virtual bool _removeWhenFarAway();
	virtual void getDeathLoot();
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity &);
	virtual void updateAi();
	virtual bool newServerAiStep();
	virtual void _serverAiMobStep();
	virtual void _getSoundVolume();
	virtual const char *_getAmbientSound();
	virtual string _getHurtSound();
	virtual string _getDeathSound();
	virtual void getDamageAfterArmorAbsorb(EntityDamageSource const &, int);
	virtual void getDamageAfterMagicAbsorb(EntityDamageSource const &, int);
	virtual void getExperienceReward() const;
	virtual bool useNewAi();
	virtual void onEffectAdded(MobEffectInstance &);
	virtual void onEffectUpdated(MobEffectInstance const &);
	virtual void onEffectRemoved(MobEffectInstance &);
	virtual void registerAttributes();
	int getMaxHealth() const;
	int getHealth() const;
	void serializationSetHealth(int);
};
