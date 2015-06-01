#pragma once

#include <string>
#include "..\client\renderer\texture\TextureUVCoordinateSet.h"
#include "..\client\renderer\texture\TextureAtlasTextureItem.h"

class TextureAtlas;
class ItemInstance;
class Player;
class Level;
class Tile;
class Entity;
class Mob;

// Size : 72
class Item
{
public:
	static Item *mobPlacer;

public:
	static Item *items[256];
	static const char *ICON_DESCRIPTION_PREFIX;
	static TextureAtlas *_itemTextureAtlas;

public:
	//void **vtable;				// 0
	int maxStackSize;				// 4
	const char *textureName;		// 8
	char filler1[8];				// 12
	int id;							// 20
	int maxDamage;					// 24
	TextureUVCoordinateSet icon;	// 28
	int category;					// 60
	bool _isHandEquipped;			// 64
	bool stackedByData;				// 65
	std::string nameId;				// 68

public:
	Item(int);
	virtual ~Item();
	virtual void getMaxStackSize(const ItemInstance *);
	virtual void setMaxStackSize(unsigned char);
	virtual void canBeDepleted();
	virtual void getIcon(int, int, bool) const;
	virtual void getIconYOffset() const;
	virtual void setIcon(const std::string &, int);
	virtual void setIcon(TextureUVCoordinateSet);
	virtual void isMirroredArt() const;
	virtual void use(ItemInstance &, Player &);
	virtual void useOn(ItemInstance *, Player*, int, int, int, signed char, float, float, float);
	virtual void getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual void getUseAnimation() const;
	virtual void releaseUsing(ItemInstance *, Player *, int);
	virtual void getDestroySpeed(ItemInstance *, Tile *);
	virtual void canDestroySpecial(const Tile *) const;
	virtual void getLevelDataForAuxValue(int) const;
	virtual void isStackedByData() const;
	virtual void getMaxDamage();
	virtual void getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void interactEnemy(ItemInstance *, Mob *, Player *);
	virtual void mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual void handEquipped();
	virtual void isHandEquipped() const;
	virtual void isFood() const;
	virtual void isSeed() const;
	virtual void isArmor() const;
	virtual void isDye() const;
	virtual void isLiquidClipItem(int) const;
	virtual void requiresInteract() const;
	virtual void getInteractText() const;
	virtual void getName(const ItemInstance *) const;
	virtual void setNameID(const std::string &);
	virtual void isEmissive(int) const;
	virtual void getAnimationFrameFor(Mob &) const;
	static void initItems();
	static void initCreativeItems();
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static ItemInstance getIDByName(const std::string &, bool);
	static void addCreativeItem(Tile *, short);
	static void addCreativeItem(Item *, short);
	static void addCreativeItem(short, short);
	void setCategory(int);
	void setStackedByData(bool);
	void setMaxDamage(int);
};
