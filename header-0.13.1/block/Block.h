#pragma once

#include <string>

class Block
{
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

	char filler[4];		// 0
	unsigned char id;	// 4

	static Block *lookupByName(const std::string &, bool);
};
