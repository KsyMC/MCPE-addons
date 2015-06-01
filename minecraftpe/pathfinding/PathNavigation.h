#pragma once

class Mob;
class Level;
class Vec3;

// Size : 48
class PathNavigation
{
public:
	PathNavigation(Mob *, Level *, float);
	virtual ~PathNavigation();
	virtual void createPath(float, float, float);
	virtual void moveTo(float, float, float, float);
	virtual void createPath(Mob *);
	virtual void moveTo(Mob *, float);
	virtual void moiveTo(std::unique_ptr<Path>, float);
	virtual void tick();
	virtual bool isDone();
	virtual void stop();
	void CanMoveDirectly(Vec3, Vec3, int, int, int);
	void canOpenDoors();
	void canPassDoors();
	void canUpdatePath();
	void canWalkAbove(int, int, int, int, int, int, Vec3, float, float);
	void canWalkOn(int, int, int, int, int, int, Vec3, float, float);
	void createPath(Mob *);
	void getAvoidWater();
	void getPath();
	void getSurfaceY();
	void getTempMobPos();
	bool isDone();
	bool isInLiquid();
	void moveTo(Mob *, float);
	void moveTo(float, float, float, float);
	void moveTo(std::unique_ptr<Path>, float);
	void setAvoidSun(bool);
	void setAvoidWater(bool);
	void setCanFloat(bool);
	void setCanOpenDoors(bool);
	void setCanPassDoors(bool);
	void setSpeed(float);
	void stop();
	void tick();
	void trimPathFromSun();
	void updatePath();
};