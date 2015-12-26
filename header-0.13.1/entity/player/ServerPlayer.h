#pragma once

#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/inventory/IContainerListener.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/level/dimension/DimensionId.h"
#include "minecraftpe/client/resources/SkinInfoData.h"
#include "minecraftpe/util/UUID.h"

class Level;
class PacketSender;
class Vec3;
class MobEffectInstance;
class Tick;
class BlockPos;
class BaseContainerMenu;

// Size : 3592
class ServerPlayer : public Player, public IContainerListener
{
public:
	//void **vtable;		// 3564
	char filler[20];		// 3568
	char containerCounter;	// 3588

	ServerPlayer(Level &, PacketSender &, GameType, RakNet::RakNetGUID const &, function<void (ServerPlayer &)>, unique_ptr<SkinInfoData>, mce::UUID);
	virtual ~ServerPlayer();
	virtual void normalTick();
	virtual void push(Vec3 const &);
	virtual void changeDimension(DimensionId);
	virtual void knockback(Entity *, int, float, float);
	virtual void aiStep();
	virtual void hurtArmor(int);
	virtual void onEffectAdded(MobEffectInstance &);
	virtual void onEffectUpdated(MobEffectInstance const &);
	virtual void onEffectRemoved(MobEffectInstance &);
	virtual void tickWorld(Tick const &);
	virtual void hasResource(int);
	virtual void openContainer(int, BlockPos const &);
	virtual void openFurnace(int, BlockPos const &);
	virtual void openEnchanter(int, BlockPos const &);
	virtual void openAnvil(BlockPos const &);
	virtual void openBrewingStand(int, BlockPos const &);
	virtual void displayLocalizableMessage(string const &, vector<string> const &);
	virtual void stopSleepInBed(bool, bool);
	virtual void setPlayerGameType(GameType);
	virtual void closeContainer();
	virtual void setContainerData(BaseContainerMenu &, int, int);
	virtual void slotChanged(BaseContainerMenu &, int, ItemInstance const &, bool);
	virtual void refreshContainer(BaseContainerMenu &, vector<ItemInstance> const &);
	void disconnect();
};
