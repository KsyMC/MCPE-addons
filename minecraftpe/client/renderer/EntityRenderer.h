#pragma once

#include <string>
#include "EntityShaderManager.h"

class EntityRendererDispatcher;
class Entity;
class Vec3;
class EntityRenderDispatcher;
class Font;

class EntityRenderer : public EntityShaderManager
{
public:
	static EntityRendererDispatcher *entityRenderDispatcher;

public:
	//void **vtable;	// 0

public:
	EntityRenderer();
	virtual ~EntityRenderer();
	virtual void render(Entity &, const Vec3 &, float, float) = 0;
	virtual void postRender(Entity &, const Vec3 &, float, float);
	virtual void renderName(Entity &, float);
	virtual void renderWaterHole(Entity &, const Vec3 &, const Vec2 &, float);
	void bindTexture(const std::string &);
	static void _emitFlame(Entity &, float);
	static void _emitSmoke(Entity &, float);
	static void init(EntityRenderDispatcher *);
	static bool isFancy();
	static Font *getFont();
};
