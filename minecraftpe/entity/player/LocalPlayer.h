#pragma once

#include "Player.h"
#include "../../inventory/IContainerListener.h"
#include "../../inventory/InventoryMenu.h"

class MinecraftClient;
class User;
class Boat;

// Size : 3664
class LocalPlayer : public Player, public IContainerListener
{
public:
	//void **vtable;				// 3444
	InventoryMenu invMenu;			// 3448
	char filler1[12];				// 3480
	MinecraftClient *mc;			// 3492
	ItemInstance itemInstance[4];	// 3596
	char filler2[4];				// 3660

public:
	LocalPlayer(MinecraftClient *, Level &, User *, bool, const RakNet::RakNetGUID &);
	virtual ~LocalPlayer();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual void move(float, float, float);
	virtual void normalTick();
	virtual void rideTick();
	virtual void startRiding(Entity &);
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void stopRiding(bool);
	virtual void actuallyHurt(int, const EntityDamageSource &);
	virtual void aiStep();
	virtual void swing();
	virtual void updateAi();
	virtual void tickWorld(const Tick &);
	virtual void respawn();
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int);
	virtual void startStonecutting(int, int, int);
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void openTextEdit(TileEntity *);
	virtual void isLocalPlayer();
	virtual void stopLoading();
	virtual void closeContainer();
	virtual void refreshContainer(BaseContainerMenu *, const std::vector<ItemInstance> &);
	virtual void slotChanged(BaseContainerMenu *, int, const ItemInstance &, bool);
	void _init();
	void _input();
	void _makeBoatInputHolder(Boat &);
	void _setRideInputFor(Entity &);
	void calculateFlight(float, float, float);
	float getFieldOfViewModifier();
	std::string getGameModeString();
	float getPreloadingProgress();
	void hurtTo(int);
	bool isSolidTile(int, int, int);
	void onViewDistanceChanged(int);
	void sendGameSessionHeartBoat(bool);
	void sendPosition();
	void updateArmorTypeHash();
};
