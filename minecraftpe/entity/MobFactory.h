#pragma once

#include <string>

class Level;
class Mob;
class TileSource;
class Vec3;
class Vec2;

// Size : 88
class MobFactory
{
public:
	int filler1;	// 0
	Level *level;	// 4

public:
	MobFactory(Level &);
	static std::string GetMobNameID(int);
	static const Mob *CreateMob(int, TileSource &, const Vec3 &, Vec2 *);
	static int _categoryID(int);
};
