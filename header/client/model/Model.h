#pragma once

#include "../AppPlatformListener.h"
#include "../renderer/MaterialPtr.h"

class Entity;
class Mob;
class AABB;

// Size : 120
class Model : public AppPlatformListener
{
public:
	// void **vtable;					// 0
	char filler1[32];					// 4
	MaterialPtr entity;					// 36
	MaterialPtr entity_alphatest;		// 48
	MaterialPtr entity_alphablend;		// 60
	MaterialPtr entity_static;			// 72
	MaterialPtr entity_emissive;		// 84
	MaterialPtr entity_emissive_alpha;	// 96
	MaterialPtr entity_change_color;	// 108

public:
	Model();
	virtual ~Model();
	virtual void onAppSuspended();
	virtual void clear();
	virtual void render();
	virtual void render(Entity &, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob &, float, float, float);
	AABB *getAABB() const;
};
