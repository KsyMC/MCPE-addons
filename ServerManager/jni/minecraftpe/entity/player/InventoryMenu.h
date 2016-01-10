#pragma once

#include "minecraftpe/inventory/BaseContainerMenu.h"

class Container;

// Size : 28
class InventoryMenu : public BaseContainerMenu
{
public:
	Container *container;	// 24

	virtual ~InventoryMenu();
	virtual void getItems();
	virtual void setSlot(int, ItemInstance &);
	virtual void getSlot(int);
	virtual void removeSlot(int, int);
	virtual void blockEntityDestroyedIsInvalid(int);
};
