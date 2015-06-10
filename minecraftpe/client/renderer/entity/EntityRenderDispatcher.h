#pragma once

#include "../../AppPlatformListener.h"

class Vec3;
class MinecraftClient;
class EntityRenderer;
class Entity;

enum EntityRendererId
{
	//RENDERER_
};

class EntityRenderDispatcher : public AppPlatformListener
{
public:
	static EntityRenderDispatcher *instance;

public:
	// void **vtable;						// 0
	char filler1[40];						// 4
	EntityRenderer *entityRenderers[34];	// 44

public:
	EntityRenderDispatcher(MinecraftClient &);
	virtual ~EntityRenderDispatcher();
	virtual void onAppSuspended();
	EntityRenderer *getRenderer(Entity &);
	EntityRenderer *getRenderer(EntityRendererId);
	void render(Entity &, const Vec3 &, float, float);
};
