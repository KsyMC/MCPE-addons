#pragma once

#include "Item.h"

// Size : 88
class ArmorItem : public Item
{
public:
	// Size : 20
	class ArmorMaterial
	{
	public:
		int i1;		// 0
		int defense;// 4
		int i3;		// 8
		int i4;		// 12
		int i5;		// 16

	public:
		ArmorMaterial(int, int, int, int, int);
		int getDefenseForSlot(int);
		int getHealthForSlot(int);
	};

public:
	static ArmorMaterial CHAIN;
	static ArmorMaterial CLOTH;
	static ArmorMaterial DIAMOND;
	static ArmorMaterial GOLD;
	static ArmorMaterial IRON;
	static int healthPerSlot[4];

public:
	int i1;							// 72
	int defence;					// 76
	int i2;							// 80
	ArmorMaterial *armorMaterial;	// 84

public:
	ArmorItem(int, const ArmorItem::ArmorMaterial &, int, int);
	virtual ~ArmorItem();
	virtual bool isArmor() const;
};
