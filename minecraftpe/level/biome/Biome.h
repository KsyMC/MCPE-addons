#pragma once

class BiomeDecorator;
class Random;
class TilePos;
class TileSource;
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
	virtual void getRandomFlowerTypeAndData(Random &, const TilePos &);
	virtual void decorate(TileSource *, Random &, const TilePos &, bool, float);
	virtual void buildSurfaceAt(Random &, LevelChunk &, const TilePos &, float);
	virtual void getGrassColor(const TilePos &);
	virtual void refreshBiome(unsigned int);
	virtual void getTemperatureCategory() const;
	virtual void isSame(Biome *);
	virtual void isHumid();
	virtual void createMutatedCopy(int);
};
