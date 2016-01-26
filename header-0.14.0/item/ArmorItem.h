#pragma once

#include "minecraftpe/item/Item.h"

class ArmorItem : public Item {
public:
	ArmorItem(const std::string&, int, ArmorItem::ArmorMaterial const&, int, ArmorSlot);
	
	virtual ~ArmorItem();
	virtual bool isArmor();
	virtual void appendFormattedHovertext(ItemInstance const&, Player const&, std::string&, bool);
	virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
	virtual int getEnchantSlot();
	virtual int getEnchantValue();
	virtual void getColor(ItemInstance const&);
	virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
};