#pragma once

class ItemInstance;
class IContainerListener;

// Size : 28
class BaseContainerMenu
{
public:
	//void **vtable;
	char filler1[8];				// 4
	IContainerListener *listener;	// 12
	char filler2[12];				// 16

public:
	BaseContainerMenu(int);
	virtual ~BaseContainerMenu();
	virtual void getItems() = 0;
	virtual void setSlot(int, ItemInstance *) = 0;
	virtual void setData(int, int);
	virtual void setListener(IContainerListener *);
	virtual void broadcastChanges();
	virtual void isResultSlot(int);
	virtual void tileEntityDestroyedIsInvalid(int) = 0;
};
