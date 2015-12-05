#pragma once

class BiomeDecorator;
class Random;
class BlockPos;
class BlockSource;
class LevelChunk;

class Biome
{
public:
	enum BiomeType
	{

	};

public:
	static Biome *beaches;
	static Biome *birchForest;
	static Biome *birchForestHills;
	static Biome *birchForestHillsMutated;
	static Biome *birchForestMutated;
	static Biome *coldBeach;
	static Biome *deepOcean;
	static Biome *defaultTotalEnemyWeight;
	static Biome *defaultTotalFriendlyWeight;
	static Biome *desert;
	static Biome *desertHills;
	static Biome *desertMutated;
	static Biome *extremeHills;
	static Biome *extremeHillsMutated;
	static Biome *extremeHillsWithTrees;
	static Biome *extremeHillsWithTreesMutated;
	static Biome *forest;
	static Biome *forestHills;
	static Biome *forestMutated;
	static Biome *frozenOcean;
	static Biome *frozenRiver;
	static Biome *hell;
	static Biome *iceFlats;
	static Biome *iceFlatsMutated;
	static Biome *iceMountains;
	static Biome *jungle;
	static Biome *jungleEdge;
	static Biome *jungleEdgeMutated;
	static Biome *jungleHills;
	static Biome *jungleMutated;
	static Biome *mesa;
	static Biome *mesaClearRock;
	static Biome *mesaClearRockMutated;
	static Biome *mesaMutated;
	static Biome *mesaRock;
	static Biome *mesaRockMutated;
	static Biome *mushroomIsland;
	static Biome *mushroomIslandShore;
	static Biome *ocean;
	static Biome *plains;
	static Biome *plainsMutated;
	static Biome *redwoodTaiga;
	static Biome *redwoodTaigaHills;
	static Biome *redwoodTaigaHillsMutated;
	static Biome *redwoodTaigaMutated;
	static Biome *river;
	static Biome *roofedForest;
	static Biome *roofedForestMutated;
	static Biome *savanna;
	static Biome *savannaMutated;
	static Biome *savannaRock;
	static Biome *savannaRockMutated;
	static Biome *sky;
	static Biome *smallerExtremeHills;
	static Biome *stoneBeach;
	static Biome *swampland;
	static Biome *swamplandMutated;
	static Biome *taiga;
	static Biome *taigaCold;
	static Biome *taigaColdHills;
	static Biome *taigaColdMutated;
	static Biome *taigaHills;
	static Biome *taigaMutated;

public:
	static Biome *mBiomes;

public:
	Biome(int, Biome::BiomeType, BiomeDecorator *);
	virtual void setColor(int);
	virtual void setColor(int, bool);
	virtual ~Biome();
	virtual void getTreeFeature(Random *);
	virtual void getGrassFeature(Random *);
	virtual void getTemperature();
	virtual void adjustScale(float);
	virtual void adjustDepth(float);
	virtual void getSkyColor(float);
	virtual void getMobs(EntityType);
	virtual void getCreatureProbability();
	virtual void getFoliageColor();
	virtual void getRandomFlowerTypeAndData(Random &, BlockPos const &);
	virtual void decorate(BlockSource *, Random &, BlockPos const &, bool, float);
	virtual void buildSurfaceAt(Random &, LevelChunk &, BlockPos const &, float);
	virtual void getGrassColor(BlockPos const &);
	virtual void refreshBiome(unsigned int);
	virtual void getTemperatureCategory() const;
	virtual void isSame(Biome *);
	virtual void isHumid();
	virtual void createMutatedCopy(int);
};
