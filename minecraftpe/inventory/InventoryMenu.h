#pragma once

#include "BaseContainerMenu.h"

// Size : 32
class InventoryMenu : public BaseContainerMenu
{
public:
	Container *container;	// 28

public:
	InventoryMenu(Container *);
	virtual ~InventoryMenu();
	virtual void getItems();
	virtual void setSlot(int, ItemInstance *);
	virtual void tileEntityDestroyedIsInvalid(int);
};
