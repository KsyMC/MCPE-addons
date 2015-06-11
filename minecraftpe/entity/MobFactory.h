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
	MobFactory(Level &);
	static std::string GetMobNameID(int);
	static const Mob *CreateMob(int, TileSource &, const Vec3 &, Vec2 *);
	static void _categoryID(int);
};
