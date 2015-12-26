#pragma once

#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/inventory/IContainerListener.h"
#include "minecraftpe/gamemode/GameType.h"
#include "minecraftpe/entity/player/InventoryMenu.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/util/UUID.h"
#include "minecraftpe/entity/EntityUniqueID.h"

class MinecraftClient;
class Level;
class User;
class Vec3;
class EntityDamageSource;
class ChangeDimensionPacket;
class CompoundTag;
class Tick;
class BlockPos;
class BlockEntity;
class BaseContainerMenu;

// Size : 3888
class LocalPlayer : public Player, public IContainerListener
{
public:
	//void **vtable;			// 3564
	InventoryMenu invMenu;		// 3568
	char filler1[8];			// 3596
	MinecraftClient *client;	// 3604
	int loadingState;			// 3608
	ItemInstance item;			// 3692
	char filler2[24];			// 3712
	ItemInstance item1;			// 3736
	ItemInstance item2;			// 3756
	ItemInstance item3;			// 3776
	ItemInstance item4;			// 3796
	char filler3[72];			// 3816

	LocalPlayer(MinecraftClient *, Level &, User const &, GameType, RakNet::RakNetGUID const &, mce::UUID);
	virtual ~LocalPlayer();
	virtual void setPos(Vec3 const &);
	virtual void move(Vec3 const &);
	virtual void normalTick();
	virtual void rideTick();
	virtual void startRiding(Entity &);
	virtual void hurt(EntityDamageSource const &, int);
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket &);
	virtual EntityUniqueID getControllingPlayer() const;
	virtual void stopRiding(bool);
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(CompoundTag const &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void die(EntityDamageSource const &);
	virtual void setSneaking(bool);
	virtual void setSprinting(bool);
	virtual void actuallyHurt(int, EntityDamageSource const *);
	virtual void aiStep();
	virtual void swing();
	virtual void setArmor(ArmorSlot, ItemInstance const *);
	virtual void drop(ItemInstance const *, bool);
	virtual void updateAi();
	virtual void destroyRegion();
	virtual void onPrepChangeDimension();
	virtual void onDimensionChanged();
	virtual void tickWorld(Tick const &);
	virtual void _checkMovementStatistiscs(Vec3 const &);
	virtual void respawn();
	virtual bool isInTrialMode();
	virtual void startCrafting(int, BlockPos const &);
	virtual void openContainer(int, BlockPos const &);
	virtual void openFurnace(int, BlockPos const &);
	virtual void openEnchanter(int, BlockPos const &);
	virtual void openAnvil(BlockPos const &);
	virtual void openBrewingStand(int, BlockPos const &);
	virtual void displayLocalizableMessage(string const &, vector<string> const &);
	virtual void startSleepInBed(BlockPos const &);
	virtual void stopSleepInBed(bool, bool);
	virtual void openTextEdit(BlockEntity *);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void _crit(Entity &);
	virtual void getTelemetry() const;
	virtual void closeContainer();
	virtual void refreshContainer(BaseContainerMenu &, vector<ItemInstance> const &);
	virtual void slotChanged(BaseContainerMenu &, int, ItemInstance const &, bool);
};
