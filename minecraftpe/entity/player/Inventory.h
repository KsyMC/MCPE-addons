#pragma once

#include "../../inventory/FillingContainer.h"

class Tile;
class Entity;

// Size : 40
class Inventory : public FillingContainer
{
public:
	Player *player;	// 36

public:
	Inventory(Player *, bool);
	virtual ~Inventory();
	virtual void getContainerSize() const;
	virtual void add(ItemInstance*);
	virtual void canAdd(const ItemInstance *) const;
	virtual void clearSlot(int);
	virtual void doDrop(ItemInstance *, bool);
	virtual void setContainerSize(int);
	bool canDestroy(Tile *);
	void clearInventoryWithDefault(bool);
	void getAttackDamage(Entity *);
	void getDestroySpeed(Tile *);
	void getLinkedSlotForItem(int);
	void getLinkedSlotForItemIdAndAux(int, int);
	void getSelectedItem() const;
	void getSelectionSize();
	void moveToEmptySelectionSlot(int);
	void moveToSelectedSlot(int);
	void moveToSelectionSlot(int, int);
	void moveToEmptySelectionSlot(int);
	void selectSlot(int);
	void setupDefault();
};
