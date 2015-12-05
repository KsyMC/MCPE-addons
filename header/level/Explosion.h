#pragma once

class BlockSource;
class Entity;

class Explosion
{
public:
	Explosion(BlockSource &, Entity *, float, float, float, float);
	void explode();
	void finalizeExplosion();
};