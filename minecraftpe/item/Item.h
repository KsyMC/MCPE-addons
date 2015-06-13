#pragma once

#include <string>
#include <memory>
#include "ActionEnum.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../client/renderer/texture/TextureAtlasTextureItem.h"

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
	// Size : 16
	class Tier
	{
	public:
		char filler1[16];	// 0
	};

public:
	static Item *apple;
	static Item *arrow;
	static Item *bed;
	static Item *beef_cooked;
	static Item *beef_raw;
	static Item *beetroot;
	static Item *beetrootSoup;
	static Item *boat;
	static Item *bone;
	static Item *book;
	static Item *boots_chain;
	static Item *boots_cloth;
	static Item *boots_diamond;
	static Item *boots_gold;
	static Item *boots_iron;
	static Item *bow;
	static Item *bowl;
	static Item *bread;
	static Item *brick;
	static Item *bucket;
	static Item *cake;
	static Item *camera;
	static Item *carrot;
	static Item *chestplate_chain;
	static Item *chestplate_cloth;
	static Item *chestplate_diamond;
	static Item *chestplate_gold;
	static Item *chestplate_iron;
	static Item *chicken_cooked;
	static Item *chicken_raw;
	static Item *clay;
	static Item *clock;
	static Item *coal;
	static Item *compass;
	static Item *cookie;
	static Item *diamond;
	static Item *door_iron;
	static Item *door_wood;
	static Item *dye_powder;
	static Item *egg;
	static Item *emerald;
	static Item *feather;
	static Item *fish_cooked;
	static Item *fish_raw;
	static Item *fishingRod;
	static Item *flint;
	static Item *flintAndSteel;
	static Item *goldIngot;
	static Item *hatchet_diamond;
	static Item *hatchet_gold;
	static Item *hatchet_iron;
	static Item *hatchet_stone;
	static Item *hatchet_wood;
	static Item *helmet_chain;
	static Item *helmet_cloth;
	static Item *helmet_diamond;
	static Item *helmet_gold;
	static Item *helmet_iron;
	static Item *hoe_diamond;
	static Item *hoe_gold;
	static Item *hoe_iron;
	static Item *hoe_stone;
	static Item *hoe_wood;
	static Item *ironIngot;
	static Item *leather;
	static Item *leggings_chain;
	static Item *leggings_cloth;
	static Item *leggings_diamond;
	static Item *leggings_gold;
	static Item *leggings_iron;
	static Item *magma_cream;
	static Item *melon;
	static Item *minecart;
	static Item *mobPlacer;
	static Item *mushroomStew;
	static Item *netherQuartz;
	static Item *netherbrick;
	static Item *painting;
	static Item *paper;
	static Item *pickAxe_diamond;
	static Item *pickAxe_gold;
	static Item *pickAxe_iron;
	static Item *pickAxe_stone;
	static Item *pickAxe_wood;
	static Item *porkChop_cooked;
	static Item *porkChop_raw;
	static Item *potato;
	static Item *potatoBaked;
	static Item *pumpkinPie;
	static Item *random;
	static Item *redStone;
	static Item *reeds;
	static Item *rotten_flesh;
	static Item *saddle;
	static Item *seeds_beetroot;
	static Item *seeds_melon;
	static Item *seeds_pumpkin;
	static Item *seeds_wheat;
	static Item *shears;
	static Item *shovel_diamond;
	static Item *shovel_gold;
	static Item *shovel_iron;
	static Item *shovel_stone;
	static Item *shovel_wood;
	static Item *sign;
	static Item *slimeBall;
	static Item *snowBall;
	static Item *stick;
	static Item *string;
	static Item *sugar;
	static Item *sulphur;
	static Item *sword_diamond;
	static Item *sword_gold;
	static Item *sword_iron;
	static Item *sword_stone;
	static Item *sword_wood;
	static Item *wheat;
	static Item *yellowDust;

public:
	Item::Tier DIAMOND;
	Item::Tier GOLD;
	Item::Tier IRON;
	Item::Tier STONE;
	Item::Tier WOOD;

public:
	static Item *items[256];
	static std::vector<ItemInstance> creativeList;

public:
	static const char *ICON_DESCRIPTION_PREFIX;
	static TextureAtlas *_itemTextureAtlas;

public:
	//void **vtable;				// 0
	int maxStackSize;				// 4
	const char *textureName;		// 8
	char filler1[6];				// 12
	short id;						// 18
	short maxDamage;				// 20
	char filler2[2];				// 22
	TextureUVCoordinateSet itemIcon;// 24
	int category;					// 56
	bool _handEquipped;				// 60
	bool stackedByData;				// 61
	char filler3[6];				// 62
	std::string nameId;				// 68

public:
	Item(int);
	virtual ~Item();
	virtual int getMaxStackSize(const ItemInstance *);
	virtual void setMaxStackSize(unsigned char);
	virtual bool canBeDepleted();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual void setIcon(const std::string &, int);
	virtual void setIcon(TextureUVCoordinateSet);
	virtual bool isMirroredArt() const;
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual int getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual ActionEnum getUseAnimation() const;
	virtual void releaseUsing(ItemInstance *, Player *, int);
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual short getMaxDamage();
	virtual void getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void interactEnemy(ItemInstance *, Mob *, Player *);
	virtual void mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual void handEquipped();
	virtual bool isHandEquipped() const;
	virtual bool isFood() const;
	virtual bool isSeed() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual std::string getInteractText() const;
	virtual std::string getName(const ItemInstance *) const;
	virtual void setNameID(const std::string &);
	virtual bool isEmissive(int) const;
	virtual void getAnimationFrameFor(Mob &) const;
	static void initItems();
	static void initCreativeItems();
	static void addCreativeItem(Item *, short);
	static void addCreativeItem(Tile *, short);
	static void addCreativeItem(short, short);
	static int getIDByName(const std::string &, bool);
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	static void teardownItems();
	bool _textMatch(const std::string &, const std::string &, bool);
	void setCategory(int);
	void setMaxDamage(int);
	void setStackedByData(bool);
};
