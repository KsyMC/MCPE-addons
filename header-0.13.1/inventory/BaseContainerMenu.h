#pragma once

#include "minecraftpe/inventory/ContainerType.h"

class ItemInstance;
class IContainerListener;

// Size : 24
class BaseContainerMenu
{
public:
	//void **vtable;	// 0
	char filler[20];	// 4

	BaseContainerMenu(ContainerType);
	virtual ~BaseContainerMenu();
	virtual void getItems() = 0;
	virtual void setSlot(int, ItemInstance &) = 0;
	virtual void getSlot(int) = 0;
	virtual void removeSlot(int, int) = 0;
	virtual void setData(int, int);
	virtual void setListener(IContainerListener *);
	virtual void broadcastChanges();
	virtual bool isSlotDirty(int);
	virtual bool isResultSlot(int);
	virtual void blockEntityDestroyedIsInvalid(int) = 0;
	int *getContainerId();
	char getContainerType() const;
	IContainerListener *getListener();
};
