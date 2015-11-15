#pragma once

#include "Item.h"

class Material;
class BlockSource;

// Size : 76
class DoorItem : public Item
{
public:
	Material *doorMaterial; // 72

public:
	DoorItem(int, const Material *);
	virtual ~DoorItem();
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	static void place(BlockSource *, int, int, int, int, Block *);
};