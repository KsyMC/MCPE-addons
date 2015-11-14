#pragma once

#include <minecraftpe/blockentity/BlockEntityType.h>
#include <string>
#include <memory>
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../client/renderer/texture/TextureAtlasTextureItem.h"
#include "../util/TileID.h"
#include "../util/AABB.h"
#include "../util/Brightness.h"

class TextureAtlas;
class Material;
class BlockSource;
class Random;
class Player;
class BlockPos;
class Entity;
class Vec3;
class Mob;
class ItemInstance;
class FullTile;
typedef int TileType;

// Size : 140
class Block
{
public:
	// Size : 20
	class SoundType
	{
	public:
		float volume;			// 0
		float pitch;			// 4
		std::string	stepSound;	// 8
		std::string breakSound;	// 12
		std::string placeSound;	// 16

	public:
		SoundType(std::string const &, float,float);
		SoundType(std::string const &, std::string const &, float, float);
		SoundType(std::string const &, std::string const &, std::string const &, float, float);
		~SoundType();
		std::string getBreakSound();
		std::string  getPlaceSound();
		std::string  getStepSound();
		float getVolume();
		float getPitch();
	};

public:
	static Block *mAcaciaFenceGate;
	static Block *mAcaciaStairs;
	static Block *mActivatorRail;
	static Block *mAir;
	static Block *mAnvil;
	static Block *mBed;
	static Block *mBedrock;
	static Block *mBeetrootCrop;
	static Block *mBirchFenceGate;
	static Block *mBirchStairs;
	static Block *mBookshelf;
	static Block *mBrewingStand;
	static Block *mBrick;
	static Block *mBrickStairs;
	static Block *mBrownMushroom;
	static Block *mBrownMushroomBlock;
	static Block *mCactus;
	static Block *mCake;
	static Block *mCarrotCrop;
	static Block *mChest;
	static Block *mClay;
	static Block *mCoalBlock;
	static Block *mCoalOre;
	static Block *mCobblestone;
	static Block *mCobblestoneWall;
	static Block *mCocoa;
	static Block *mDarkOakFenceGate;
	static Block *mDarkOakStairs;
	static Block *mDaylightDetector;
	static Block *mDaylightDetectorInverted;
	static Block *mDeadBush;
	static Block *mDetectorRail;
	static Block *mDiamondBlock;
	static Block *mDiamondOre;
	static Block *mDirt;
	static Block *mDoublePlant;
	static Block *mDoubleStoneSlab;
	static Block *mDoubleWoodenSlab;
	static Block *mEmeraldBlock;
	static Block *mEmeraldOre;
	static Block *mEnchantingTable;
	static Block *mEndPortalFrame;
	static Block *mEndStone;
	static Block *mFarmland;
	static Block *mFence;
	static Block *mFenceGateOak;
	static Block *mFire;
	static Block *mFlowerPot;
	static Block *mFlowingLava;
	static Block *mFlowingWater;
	static Block *mFurnace;
	static Block *mGlass;
	static Block *mGlassPane;
	static Block *mGlowStone;
	static Block *mGlowingObsidian;
	static Block *mGoldBlock;
	static Block *mGoldOre;
	static Block *mGoldenRail;
	static Block *mGrass;
	static Block *mGrassPathBlock;
	static Block *mGravel;
	static Block *mHardenedClay;
	static Block *mHayBlock;
	static Block *mHeavyWeightedPressurePlate;
	static Block *mIce;
	static Block *mInfoReserved6;
	static Block *mInfoUpdateGame1;
	static Block *mInfoUpdateGame2;
	static Block *mInvisibleBedrock;
	static Block *mIronBlock;
	static Block *mIronDoor;
	static Block *mIronFence;
	static Block *mIronOre;
	static Block *mIronTrapdoor;
	static Block *mJungleFenceGate;
	static Block *mJungleStairs;
	static Block *mLadder;
	static Block *mLapisBlock;
	static Block *mLapisOre;
	static Block *mLeaves;
	static Block *mLeaves2;
	static Block *mLever;
	static Block *mLightWeightedPressurePlate;
	static Block *mLitFurnace;
	static Block *mLitPumpkin;
	static Block *mLitRedStoneLamp;
	static Block *mLitRedStoneOre;
	static Block *mLitRedStoneTorch;
	static Block *mLog;
	static Block *mLog2;
	static Block *mMelon;
	static Block *mMelonStem;
	static Block *mMobSpawner;
	static Block *mMonsterStoneEgg;
	static Block *mMossyCobblestone;
	static Block *mMycelium;
	static Block *mNetherBrick;
	static Block *mNetherBrickStairs;
	static Block *mNetherFence;
	static Block *mNetherReactor;
	static Block *mNetherWart;
	static Block *mNetherrack;
	static Block *mNote;
	static Block *mOakStairs;
	static Block *mObsidian;
	static Block *mPackedIce;
	static Block *mPodzol;
	static Block *mPortal;
	static Block *mPotatoCrop;
	static Block *mPumpkin;
	static Block *mPumpkinStem;
	static Block *mQuartzBlock;
	static Block *mQuartzOre;
	static Block *mQuartzStairs;
	static Block *mRail;
	static Block *mRedFlower;
	static Block *mRedMushroom;
	static Block *mRedMushroomBlock;
	static Block *mRedStoneDust;
	static Block *mRedStoneOre;
	static Block *mRedstoneBlock;
	static Block *mReeds;
	static Block *mSand;
	static Block *mSandStone;
	static Block *mSandstoneStairs;
	static Block *mSapling;
	static Block *mSign;
	static Block *mSkull;
	static Block *mSnow;
	static Block *mSoulSand;
	static Block *mSponge;
	static Block *mSpruceStairs;
	static Block *mSpuceFenceGate;
	static Block *mStainedClay;
	static Block *mStillLava;
	static Block *mStillWater;
	static Block *mStone;
	static Block *mStoneBrick;
	static Block *mStoneBrickStairs;
	static Block *mStoneButton;
	static Block *mStonePressurePlate;
	static Block *mStoneSlab;
	static Block *mStoneStairs;
	static Block *mStonecutterBench;
	static Block *mTNT;
	static Block *mTallgrass;
	static Block *mTopSnow;
	static Block *mTorch;
	static Block *mTrapdoor;
	static Block *mTrappedChest;
	static Block *mTripwire;
	static Block *mTripwireHook;
	static Block *mUnlitRedStoneLamp;
	static Block *mUnlitRedStoneTorch;
	static Block *mVine;
	static Block *mWallSign;
	static Block *mWaterlily;
	static Block *mWeb;
	static Block *mWheatCrop;
	static Block *mWoodButton;
	static Block *mWoodPlanks;
	static Block *mWoodPressurePlate;
	static Block *mWoodenDoor;
	static Block *mWoodenDoorAcacia;
	static Block *mWoodenDoorBirch;
	static Block *mWoodenDoorDarkOak;
	static Block *mWoodenDoorJungle;
	static Block *mWoodenDoorSpruce;
	static Block *mWoodenSlab;
	static Block *mWool;
	static Block *mWoolCarpet;
	static Block *mWorkBench;
	static Block *mYellowFlower;

public:
	static SoundType SOUND_ANVIL;
	static SoundType SOUND_CLOTH;
	static SoundType SOUND_GLASS;
	static SoundType SOUND_GRASS;
	static SoundType SOUND_GRAVEL;
	static SoundType SOUND_LADDER;
	static SoundType SOUND_METAL;
	static SoundType SOUND_NORMAL;
	static SoundType SOUND_SAND;
	static SoundType SOUND_SILENT;
	static SoundType SOUND_SNOW;
	static SoundType SOUND_STONE;
	static SoundType SOUND_WOOD;

public:
	static Block *mBlockLookupMap;
	static Block *mBlocks[255];
	static Block *mLightBlock[255];
	static Block *mLightEmission[255];
	static Block *mOwnedBlocks;
	static bool mShouldTick[255];
	static bool mSolid[255];
	static float mTranslucency[255];

public:
	static TextureAtlas *mTerrainTextureAtlas;
	static const char *TILE_DESCRIPTION_PREFIX;

public:
	//void **vtable;					// 0
	char filler1[4];					// 4
	AABB aabb;							// 8
	TextureUVCoordinateSet blockIcon;	// 36
	TileID tileID;						// 68
	Block::SoundType	stepSound;		// 72
	int blockRendererId;				// 84
	char filler2[20];					// 88
	Material *blockMaterial;			// 108
	char filler3[4];					// 112
	float blockHardness;				// 116
	float blockResistance;				// 120
	int category;						// 124
	char filler4[8];					// 128
	std::string unlocalizedName;		// 136

public:
	Block(std::string const &, int, Material const &);
	Block(std::string const &, int, TextureUVCoordinateSet,Material const &);
	Block(std::string const &, int, std::string const &, Material const &);
	virtual ~Block();
	virtual void tick(BlockSource &, BlockPos const &, Random &);
	virtual void animateTick(BlockSource &, BlockPos const &, Random &);
	virtual void getVisualShape(BlockSource &, BlockPos const &, AABB &, bool);
	virtual void getVisualShape(unsigned char, AABB &, bool);
	virtual void getCollisionShape(AABB &, BlockSource &, BlockPos const &, Entity *);
	virtual void isObstructingChests(BlockSource &, BlockPos const &);
	virtual void shouldRenderFace(BlockSource &, BlockPos const &, signed char, AABB const &) const;
	virtual void getTexture(signed char);
	virtual void getTexture(signed char, int);
	virtual void getTexture(BlockSource &, BlockPos const &, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual void addAABBs(BlockSource &, BlockPos const &, AABB const *, std::vector<AABB, std::allocator<AABB> > &);
	virtual void getAABB(BlockSource &, BlockPos const &, AABB &, int, bool, int);
	virtual void addCollisionShapes(BlockSource &, BlockPos const &, AABB const *, std::vector<AABB, std::allocator<AABB> > &, Entity *);
	virtual void isCropBlock() const;
	virtual void isContainerBlock() const;
	virtual void isCraftingBlock() const;
	virtual void isInteractiveBlock() const;
	virtual void isWaterBlocking() const;
	virtual void isDoorBlock() const;
	virtual void isRedstoneBlock() const;
	virtual void isRedstoneAttachable() const;
	virtual void waterSpreadCausesSpawn() const;
	virtual void getRenderLayer(BlockSource &, BlockPos const &) const;
	virtual void getThickness() const;
	virtual void checkIsPathable(Entity &, BlockPos const &, BlockPos const &);
	virtual void onPlace(BlockSource &, BlockPos const &);
	virtual void onRemove(BlockSource &, BlockPos const &);
	virtual void onExploded(BlockSource &, BlockPos const &, Entity *);
	virtual void onStepOn(Entity &, BlockPos const &);
	virtual void onFallOn(BlockSource &, BlockPos const &, Entity *, float);
	virtual void onRedstoneUpdate(BlockSource &, BlockPos const &, int, bool);
	virtual void onLoaded(BlockSource &, BlockPos const &);
	virtual void onFertilized(BlockSource &, BlockPos const &, Player *);
	virtual void mayConsumeFertilizer(BlockSource &);
	virtual void mayPick();
	virtual void mayPick(BlockSource &, int, bool);
	virtual void mayPlace(BlockSource &, BlockPos const &, signed char);
	virtual void mayPlace(BlockSource &, BlockPos const &);
	virtual void tryToPlace(BlockSource &, BlockPos const &, unsigned char);
	virtual void destroy(BlockSource &, BlockPos const &, int, Entity *);
	virtual void playerWillDestroy(Player &, BlockPos const &, int);
	virtual void neighborChanged(BlockSource &, BlockPos const &, BlockPos const &);
	virtual void getSecondPart(BlockSource &, BlockPos const &, BlockPos &);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual void getResource(Random &, int, int);
	virtual void getResourceCount(Random &, int, int);
	virtual void asItemInstance(BlockSource &, BlockPos const &, int) const;
	virtual void getDestroyProgress(Player &);
	virtual void spawnResources(BlockSource &, BlockPos const &, int, float, int);
	virtual void spawnBurnResources(BlockSource &, float, float, float);
	virtual void getExplosionResistance(Entity *);
	virtual void clip(BlockSource &, BlockPos const &, Vec3 const &, Vec3 const &, bool, int);
	virtual void use(Player &, BlockPos const &);
	virtual void getPlacementDataValue(Mob &, BlockPos const &, signed char, Vec3 const &, int);
	virtual void prepareRender(BlockSource &, BlockPos const &);
	virtual void attack(Player *, BlockPos const &);
	virtual void handleEntityInside(BlockSource &, BlockPos const &, Entity *, Vec3 &);
	virtual void getColor(int);
	virtual void getColor(BlockSource &, BlockPos const &);
	virtual void isSeasonTinted(BlockSource &, BlockPos const &) const;
	virtual void entityInside(BlockSource &, BlockPos const &, Entity &);
	virtual void playerDestroy(Player *, BlockPos const &, int);
	virtual void canSurvive(BlockSource &, BlockPos const &);
	virtual void getExperienceDrop(Random &) const;
	virtual void canBeBuiltOver(BlockSource &, BlockPos const &) const;
	virtual void buildDescriptionName(ItemInstance const &) const;
	virtual void triggerEvent(BlockSource &, BlockPos const &, int, int);
	virtual void getTextureNum(int);
	virtual void getMobToSpawn(BlockSource &, BlockPos const &) const;
	virtual void getIconYOffset() const;
	virtual void shouldStopFalling(Entity &);
	virtual void calcGroundFriction(Mob &, BlockPos const &) const;
	virtual void canHaveExtraData() const;
	virtual void init();
	virtual void canBeSilkTouched() const;
	virtual void getSilkTouchItemInstance(unsigned char);
	virtual void setVisualShape(Vec3 const &, Vec3 const &);
	virtual void setSoundType(Block::SoundType const &);
	virtual void setLightBlock(Brightness);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setFriction(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(unsigned char);
	static void initTiles();
	static Tile *getLightEmission(TileID);
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static Material *getTileMaterial(int);
	static bool isFaceVisible(TileSource *, int, int, int, signed char);
	static bool isTileType(const FullTile &, TileType);
	static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	static void teardownTiles();
	void _getTypeToSpawn(TileSource &, int, const TilePos &) const;
	void addAABB(const AABB &, const AABB *, std::vector<AABB> &);
	void destroyEffect(TileSource &, const TilePos &, const Vec3 &);
	float getShadeBrightness() const;
	bool isLiquidTile() const;
	bool isObstructingChests(TileSource *, const TilePos &);
	void popResource(TileSource *, int, int, int, const ItemInstance &);
	void setCategory(int);
	void transformToValidBlockId(TileID);
	void transformToValidBlockId(TileID, int, int, int);
};
