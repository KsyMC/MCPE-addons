#ifndef __MOBFACTORY_H__
#define __MOBFACTORY_H__

class Level;
class Mob;
class TileSource;
struct Vec3;

class MobFactory {
public:
	MobFactory::MobFactory(Level &);
	static std::string GetMobNameID(int);
	static Mob *CreateMob(int, TileSource &, const Vec3 &, Vec3*);
};

#endif
