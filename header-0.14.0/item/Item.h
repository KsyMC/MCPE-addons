#pragma once

#include <string>

class TextureUVCoordinateSet;
enum CreativeItemCategory;
enum UseAnimation;
class Block;
class ItemInstance;
class Player;
class BlockSource;
class Level;
class Mob;
struct BlockID;
class IDataInput;
class IDataOutput;
class Entity;

class Item {
public:
	Item(const std::string&, short);
	
	virtual ~Item();
	virtual void setIcon(const std::string&, int);
	virtual void setIcon(TextureUVCoordinateSet const&);
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(CreativeItemCategory);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped();
	virtual void setUseAnimation(UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual bool canBeDepleted();
	virtual bool canDestroySpecial(Block const*);
	virtual void getLevelDataForAuxValue(int);
	virtual bool isStackedByData();
	virtual short getMaxDamage();
	virtual int getAttackDamage();
	virtual bool isHandEquipped();
	virtual bool isArmor();
	virtual bool isDye();
	virtual bool isFoil(ItemInstance const*);
	virtual bool isThrowable();
	virtual bool canDestroyInCreative();
	virtual bool isLiquidClipItem(int);
	virtual bool requiresInteract();
	virtual void appendFormattedHovertext(ItemInstance const&, Player const&, std::string&, bool);
	virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
	virtual int getEnchantSlot();
	virtual int getEnchantValue();
	virtual bool isComplex();
	virtual void getColor(ItemInstance const&);
	virtual void use(ItemInstance&, Player&);
	virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual void buildDescriptionName(ItemInstance const&);
	virtual void buildEffectDescriptionName(ItemInstance const&);
	virtual void readUserData(ItemInstance*, IDataInput&);
	virtual void writeUserData(ItemInstance const*, IDataOutput&, bool);
	virtual unsigned char getMaxStackSize(ItemInstance const*);
	virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
	virtual void onCraftedBy(ItemInstance&, Level&, Player&);
	virtual void getInteractText();
	virtual void getAnimationFrameFor(Mob&);
	virtual bool isEmissive(int);
	virtual void getIcon(int, int, bool);
	virtual void getIconYOffset();
	virtual bool isMirroredArt();
};