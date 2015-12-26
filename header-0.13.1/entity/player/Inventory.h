#pragma once

#include "minecraftpe/inventory/FillingContainer.h"

// Size : 36
class Inventory : public FillingContainer
{
public:
	virtual ~Inventory();
	virtual int getContainerSize() const;
	virtual void add(ItemInstance &);
	virtual bool canAdd(ItemInstance const &) const;
	virtual void clearSlot(int);
	virtual void doDrop(ItemInstance &, bool);
	virtual void getEmptySlotsCount() const;
	virtual void setContainerSize(int);
};
