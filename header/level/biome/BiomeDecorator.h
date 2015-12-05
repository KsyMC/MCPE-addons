#pragma once

class BlockSource;
class Random;
class BlockPos;

// Size : 252
class BiomeDecorator
{
public:
	BiomeDecorator();
	virtual void decorateOres(BlockSource *, Random &, BlockPos const &);
	virtual ~BiomeDecorator();
	void _getRandomHeight(int, int, BlockSource *, Random &, BlockPos const &);
	void _getRandomSolidPosition(BlockSource *, BlockPos const &, Random &);
	void _getRandomSurfacePosition(BlockSource *, BlockPos const &, Random &);
	void _getRandomTreePosition(BlockSource *, BlockPos const &, Random &);
	void _placeFeature(BlockSource *, std::unique_ptr<Feature> const &, BlockPos const &, Random &);
	void decorate(BlockSource *, Random &, Biome *, BlockPos const &, bool, float);
	void decorateDepthAverage(BlockSource *, Random &, BlockPos const &, int, std::unique_ptr<Feature> &, int, int);
	void decorateDepthSpan(BlockSource *, Random &, BlockPos const &, int, std::unique_ptr<Feature> &, int, int);
	void decorateOres(BlockSource *, Random &, BlockPos const &);
};
