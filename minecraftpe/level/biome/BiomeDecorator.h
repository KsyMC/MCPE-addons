#pragma once

class BlockSource;
class Random;
class BlockPos;

class BiomeDecorator
{
public:
	virtual void decorateOres(BlockSource *, Random &, const BlockPos &);
	virtual ~BiomeDecorator();
};
