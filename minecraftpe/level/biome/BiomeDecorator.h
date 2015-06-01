#pragma once

class TileSource;
class Random;
class TilePos;

class BiomeDecorator
{
public:
	virtual void decorateOres(TileSource *, Random &, const TilePos &);
	virtual ~BiomeDecorator();
};
