#pragma once

#include "shared.h"

class Block;
class Item;
class CompoundTag;

// Size : 20
class ItemInstance
{
public:
	unsigned char count;	// 0
	unsigned short auxValue;// 2
	unsigned char id;		// 4
	CompoundTag *tag;		// 8
	Item *item;				// 12
	Block *block;			// 16

	ItemInstance();
	ItemInstance(bool);

	ItemInstance(Block const *block);
	ItemInstance(Block const *block, int count);
	ItemInstance(Block const *block, int count, int auxValue);

	ItemInstance(Item const *item);
	ItemInstance(Item const *item, int count);
	ItemInstance(Item const *item, int count, int auxValue);
	ItemInstance(Item const *item, int count, int auxValue, CompoundTag const *tag);

	ItemInstance(int id, int count, int auxValue);
	ItemInstance(int id, int count, int auxValue, CompoundTag const *tag);

	bool operator!=(ItemInstance const &other) const;
	bool operator==(ItemInstance const &other) const;

	ItemInstance &operator=(ItemInstance const &other);

	void set(int count);
	void add(int count);

	void setAuxValue(short auxValue);

	unsigned short getId() const;
	unsigned short getAuxValue() const;

	unsigned char getMaxStackSize() const;

	string getName() const;
};
