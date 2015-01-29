#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "FillingContainer.h"

class Player;
class ItemInstance;

class Inventory : public FillingContainer {
public:
	// Size : 48

public:
	Inventory(Player *, bool);
	virtual ~Inventory();
	virtual int getContainerSize();
	virtual bool stillValid(Player *);
	virtual void add(ItemInstance *);
	virtual void doDrop(ItemInstance *, bool);
};

#endif
