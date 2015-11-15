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
	virtual void getMobs(int);
	virtual void getCreatureProbability();
	virtual void getFoliageColor();
	virtual void getRandomFlowerTypeAndData(Random &, const BlockPos &);
	virtual void decorate(BlockSource *, Random &, const BlockPos &, bool, float);
	virtual void buildSurfaceAt(Random &, LevelChunk &, const BlockPos &, float);
	virtual void getGrassColor(const BlockPos &);
	virtual void refreshBiome(unsigned int);
	virtual void getTemperatureCategory() const;
	virtual void isSame(Biome *);
	virtual void isHumid();
	virtual void createMutatedCopy(int);
};
