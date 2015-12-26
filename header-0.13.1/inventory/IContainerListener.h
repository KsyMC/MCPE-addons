#pragma once

#include "shared.h"
#include "minecraftpe/item/ItemInstance.h"

class BaseContainerMenu;

class IContainerListener
{
public:
	virtual ~IContainerListener();
	virtual void refreshContainer(BaseContainerMenu &, vector<ItemInstance> const &);
	virtual void slotChanged(BaseContainerMenu &, int, ItemInstance const &, bool);
	virtual void setContainerData(BaseContainerMenu &, int, int);
};
