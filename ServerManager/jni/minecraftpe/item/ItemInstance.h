#pragma once

#include <string>

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
	ItemInstance(const ItemInstance &itemInstance);

	ItemInstance(const Block *block);
	ItemInstance(const Block *block, int count);
	ItemInstance(const Block *block, int count, int auxValue);

	ItemInstance(const Item *item);
	ItemInstance(const Item *item, int count);
	ItemInstance(const Item *item, int count, int auxValue);
	ItemInstance(const Item *item, int count, int auxValue, const CompoundTag *tag);

	ItemInstance(int id, int count, int auxValue);
	ItemInstance(int id, int count, int auxValue, const CompoundTag *tag);

	bool operator!=(const ItemInstance &other) const;
	bool operator==(const ItemInstance &other) const;

	bool isNull() const;
	static bool isItem(const ItemInstance *other);

	ItemInstance &operator=(const ItemInstance &other);

	void set(int count);
	void add(int count);

	void setAuxValue(short auxValue);

	unsigned short getId() const;
	unsigned short getAuxValue() const;

	unsigned char getMaxStackSize() const;

	std::string getName() const;
};
