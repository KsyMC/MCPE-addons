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
class Block;
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
	static Item *mApple;
	static Item *mApple_enchanted;
	static Item *mApple_gold;
	static Item *mArrow;
	static Item *mBed;
	static Item *mBeef_cooked;
	static Item *mBeef_raw;
	static Item *mBeetroot;
	static Item *mBeetrootSoup;
	static Item *mBlazePowder;
	static Item *mBlazeRod;
	static Item *mBoat;
	static Item *mBone;
	static Item *mBook;
	static Item *mBoots_chain;
	static Item *mBoots_cloth;
	static Item *mBoots_diamond;
	static Item *mBoots_gold;
	static Item *mBoots_iron;
	static Item *mBow;
	static Item *mBowl;
	static Item *mBread;
	static Item *mBrewing_stand;
	static Item *mBrick;
	static Item *mBucket;
	static Item *mCake;
	static Item *mCamera;
	static Item *mCarrot;
	static Item *mChestplate_chain;
	static Item *mChestplate_cloth;
	static Item *mChestplate_diamond;
	static Item *mChestplate_gold;
	static Item *mChestplate_iron;
	static Item *mChicken_cooked;
	static Item *mChicken_raw;
	static Item *mClay;
	static Item *mClock;
	static Item *mCoal;
	static Item *mCompass;
	static Item *mCookie;
	static Item *mDiamond;
	static Item *mDoor_acacia;
	static Item *mDoor_birch;
	static Item *mDoor_darkoak;
	static Item *mDoor_iron;
	static Item *mDoor_jungle;
	static Item *mDoor_spruce;
	static Item *mDoor_wood;
	static Item *mDye_powder;
	static Item *mEgg;
	static Item *mEmerald;
	static Item *mEnchanted_book;
	static Item *mExperiencePotionItem;
	static Item *mFeather;
	static Item *mFermented_spider_eye;
	static Item *mFish_cooked_cod;
	static Item *mFish_cooked_salmon;
	static Item *mFish_raw_clownfish;
	static Item *mFish_raw_cod;
	static Item *mFish_raw_pufferfish;
	static Item *mFish_raw_salmon;
	static Item *mFishingRod;
	static Item *mFlint;
	static Item *mFlintAndSteel;
	static Item *mFlowerPot;
	static Item *mGhast_tear;
	static Item *mGlass_bottle;
	static Item *mGoldIngot;
	static Item *mGold_nugget;
	static Item *mGoldenCarrot;
	static Item *mHatchet_diamond;
	static Item *mHatchet_gold;
	static Item *mHatchet_iron;
	static Item *mHatchet_stone;
	static Item *mHatchet_wood;
	static Item *mHelmet_chain;
	static Item *mHelmet_cloth;
	static Item *mHelmet_diamond;
	static Item *mHelmet_gold;
	static Item *mHelmet_iron;
	static Item *mHoe_diamond;
	static Item *mHoe_gold;
	static Item *mHoe_iron;
	static Item *mHoe_stone;
	static Item *mHoe_wood;
	static Item *mIronIngot;
	static Item *mLeather;
	static Item *mLeggings_chain;
	static Item *mLeggings_cloth;
	static Item *mLeggings_diamond;
	static Item *mLeggings_gold;
	static Item *mLeggings_iron;
	static Item *mMagma_cream;
	static Item *mMelon;
	static Item *mMinecart;
	static Item *mMobPlacer;
	static Item *mMushroomStew;
	static Item *mNetherQuartz;
	static Item *mNether_wart;
	static Item *mNetherbrick;
	static Item *mPainting;
	static Item *mPaper;
	static Item *mPickAxe_diamond;
	static Item *mPickAxe_gold;
	static Item *mPickAxe_iron;
	static Item *mPickAxe_stone;
	static Item *mPickAxe_wood;
	static Item *mPoisonous_potato;
	static Item *mPorkChop_cooked;
	static Item *mPorkChop_raw;
	static Item *mPotato;
	static Item *mPotatoBaked;
	static Item *mPotion;
	static Item *mPumpkinPie;
	static Item *mRabbitCooked;
	static Item *mRabbitFoot;
	static Item *mRabbitHide;
	static Item *mRabbitRaw;
	static Item *mRabbitStew;
	static Item *mRedStone;
	static Item *mReeds;
	static Item *mRotten_flesh;
	static Item *mSaddle;
	static Item *mSeeds_beetroot;
	static Item *mSeeds_melon;
	static Item *mSeeds_pumpkin;
	static Item *mSeeds_wheat;
	static Item *mShears;
	static Item *mShovel_diamond;
	static Item *mShovel_gold;
	static Item *mShovel_iron;
	static Item *mShovel_stone;
	static Item *mShovel_wood;
	static Item *mSign;
	static Item *mSkull;
	static Item *mSlimeBall;
	static Item *mSnowBall;
	static Item *mSpeckled_melon;
	static Item *mSpider_eye;
	static Item *mSplash_potion;
	static Item *mStick;
	static Item *mString;
	static Item *mSugar;
	static Item *mSulphur;
	static Item *mSword_diamond;
	static Item *mSword_gold;
	static Item *mSword_iron;
	static Item *mSword_stone;
	static Item *mSword_wood;
	static Item *mWheat;
	static Item *mYellowDust;

public:
	Item::Tier DIAMOND;
	Item::Tier GOLD;
	Item::Tier IRON;
	Item::Tier STONE;
	Item::Tier WOOD;

public:
	static Item *mItemLookupMap;
	static Item *mItems[256];
	static Item *mRandom;
	static std::vector<ItemInstance> mCreativeList;

public:
	static const char *ICON_DESCRIPTION_PREFIX;
	static TextureAtlas *mItemTextureAtlas;

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
	virtual void setIcon(std::string const &, int);
	virtual void setIcon(TextureUVCoordinateSet const &);
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(CreativeItemCategory);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped();
	virtual void setUseAnimation(UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual void canBeDepleted();
	virtual void canDestroySpecial(Block const *) const;
	virtual void getLevelDataForAuxValue(int) const;
	virtual void isStackedByData() const;
	virtual void getMaxDamage();
	virtual void getAttackDamage();
	virtual void isHandEquipped() const;
	virtual void isArmor() const;
	virtual void isDye() const;
	virtual void isFoil(ItemInstance const *) const;
	virtual void isThrowable() const;
	virtual void canDestroyInCreative() const;
	virtual void isLiquidClipItem(int) const;
	virtual void requiresInteract() const;
	virtual void appendFormattedHovertext(std::string &, ItemInstance const &) const;
	virtual void isValidRepairItem(ItemInstance const &, ItemInstance const &);
	virtual void getEnchantSlot() const;
	virtual void getEnchantValue() const;
	virtual void use(ItemInstance &, Player &);
	virtual void useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual void releaseUsing(ItemInstance *, Player *, int);
	virtual void getDestroySpeed(ItemInstance *, Block *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void interactEnemy(ItemInstance *, Mob *, Player *);
	virtual void mineBlock(ItemInstance *, BlockID, int, int, int, Mob *);
	virtual void buildDescriptionName(ItemInstance const &) const;
	virtual void buildEffectDescriptionName(ItemInstance const &) const;
	virtual void readUserData(ItemInstance *, RakNet::BitStream *) const;
	virtual void writeUserData(ItemInstance const *, RakNet::BitStream *, bool) const;
	virtual void getMaxStackSize(ItemInstance const *);
	virtual void getInteractText() const;
	virtual void getAnimationFrameFor(Mob &) const;
	virtual void isEmissive(int) const;
	virtual void getIcon(int, int, bool) const;
	virtual void getIconYOffset() const;
	virtual void isMirroredArt() const;
	static void initItems();
	static void initCreativeItems();
	static void addCreativeItem(Item *, short);
	static void addCreativeItem(Block *, short);
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
