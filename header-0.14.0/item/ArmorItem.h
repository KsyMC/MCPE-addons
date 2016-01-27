#pragma once

#include "minecraftpe/item/Item.h"

class Color;
class Container;

class ArmorItem : public Item {
public:
	
public:
	class ArmorMaterial {
	public:
		int slotProtections[4];	// 16
		int enchantValue;			// 20
		int durabilityMultiplier;	// 24
	public:
		ArmorMaterial(int, int, int, int, int, int);
		
		int getDefenseForSlot(ArmorSlot) const;
		int getEnchantValue() const;
		int getHealthForSlot(ArmorSlot) const;
	};
public:
	ArmorItem(const std::string&, int, const ArmorItem::ArmorMaterial&, int, ArmorSlot);
	
	static int mHealthPerSlot[];
	
	virtual ~ArmorItem();
	virtual bool isArmor();
	virtual void appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool);
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot();
	virtual int getEnchantValue();
	virtual void getColor(const ItemInstance&) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	void clearColor(ItemInstance&);
	static Item* getArmorForSlot(ArmorSlot, int);
	static ArmorSlot getSlotForItem(const ItemInstance&);
	ItemInstance& getTierItem() const;
	bool hasCustomColor(const ItemInstance&) const;
	void setColor(ItemInstance*, const Color*);
};