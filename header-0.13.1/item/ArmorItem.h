#pragma once

#include <string>

#include "minecraftpe/entity/ArmorSlot.h"
#include "minecraftpe/item/Item.h"
#include "minecraftpe/item/ItemInstance.h"

class ArmorItem : public Item {
public:
	
	class ArmorMaterial {
	public:
		int maxDamageFactor;
		int slotProtections[4];
		int enchantability;
		
	public:
		ArmorMaterial(int maxDamFactor, int helmetProtection, int chestplateProtection, int leggingsProtection, int bootsProtection, int enchantab);
		
		int getDefenseForSlot(ArmorSlot) const;
		int getEnchantValue() const;
		int getHealthForSlot(ArmorSlot) const;
	};
	
public:
	
	static const ArmorItem::ArmorMaterial CLOTH;
	static const ArmorItem::ArmorMaterial CHAIN;
	static const ArmorItem::ArmorMaterial IRON;
	static const ArmorItem::ArmorMaterial GOLD;
	static const ArmorItem::ArmorMaterial DIAMOND;
	
	static const int mHealthPerSlot[];
	
	ArmorItem(const std::string& name, int id, const ArmorItem::ArmorMaterial& armormaterial, int armorIndex, ArmorSlot slot);
	
	virtual ~ArmorItem();
	virtual bool isArmor();
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot();
	virtual int getEnchantValue();
	
	static Item* getArmorForSlot(ArmorSlot, int);
	ItemInstance& getTierItem() const;
	
};
