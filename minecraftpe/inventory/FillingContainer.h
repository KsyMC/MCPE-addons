#pragma once

#include <vector>
#include "Container.h"
#include "../item/ItemInstance.h"

class ListTag;

// Size : 32
class FillingContainer : public Container
{
public:
	FillingContainer(int, int, int, bool);
	virtual ~FillingContainer();
	virtual ItemInstance *getItem(int) const;
	virtual void setItem(int, ItemInstance *);
	virtual void removeItem(int, int);
	virtual std::string getName() const;
	virtual int getMaxStackSize() const;
	virtual void startOpen(Player &);
	virtual void stopOpen(Player &);
	virtual void add(ItemInstance *);
	virtual bool canAdd(const ItemInstance *) const;
	virtual void clearSlot(int);
	virtual void doDrop(ItemInstance *, bool);
	void addItem(ItemInstance *);
	void addResource(const ItemInstance &);
	void clearInventory(int);
	void compressLinkedSlotList(int);
	bool contains(ItemInstance *) const;
	void dropAll(bool);
	void dropSlot(int, bool, bool);
	void fixBackwardCompabilityItem(ItemInstance &);
	void getEmptySlotsCount() const;
	void getFreeSlot() const;
	void getLinked(int) const;
	void getLinkedSlot(int) const;
	void getLinkedSlotsCount() const;
	void getNonEmptySlot(int) const;
	void getNonEmptySlot(int, int) const;
	void getSlot(int) const;
	void getSlot(int, int) const;
	void getSlotWithRemainingSpace(const ItemInstance &) const;
	void hasResource(int);
	void linkEmptySlot(int);
	void linkSlot(int, int);
	void load(const ListTag *);
	void release(int);
	void removeResource(const ItemInstance &);
	void removeResource(const ItemInstance &, bool);
	void removeResource(int);
	void replace(std::vector<ItemInstance>, int);
	void replaceSlot(int, ItemInstance *);
	void save();
	void setContainerChanged();
	void swapSlots(int, int);
	void unlinkSlot(int);
};
