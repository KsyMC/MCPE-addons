#pragma once

#include "EntityRenderer.h"

class Model;
class Mob;
class Matrix;

// Size : 108
class MobRenderer : public EntityRenderer
{
public:
	bool wtf;			// 68
	Model *mainModel;	// 72
	Model *armorModel;	// 76
	char filler1[28];	// 80

public:
	MobRenderer(Model *, float);
	virtual ~MobRenderer();
	virtual void render(Entity &, const Vec3 &, float, float);
	virtual void prepareArmor(Mob &, int, float);
	virtual void setupPosition(Entity &, const Vec3 &, Matrix &);
	virtual void setupRotations(Entity &, float, float, Matrix &, float);
	virtual void getAttackAnim(Mob &, float);
	virtual void getBob(Mob &, float);
	virtual void getFlipDegrees(Mob &);
	virtual void scale(Mob &, Matrix &, float);
	virtual void additionalRendering(Mob &, float);
	virtual void bindMobTexture(Mob &);
};
