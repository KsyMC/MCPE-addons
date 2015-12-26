#pragma once

#include "Container.h"

// Size : 32
class FillingContainer : public Container
{
public:
	virtual ~FillingContainer();
	virtual ItemInstance *getItem(int) const;
	virtual void setItem(int, ItemInstance *);
	virtual void removeItem(int, int);
	virtual void getName() const;
	virtual void getMaxStackSize() const;
	virtual void startOpen(Player &);
	virtual void stopOpen(Player &);
	virtual void add(ItemInstance &);
	virtual bool canAdd(ItemInstance const &) const;
	virtual void clearSlot(int);
	virtual void doDrop(ItemInstance &, bool);
	virtual void getEmptySlotsCount() const;
};
