#pragma once

#include "../MaterialPtr.h"

class Entity;
class Color;
class TileSource;
class TilePos;

// Size : 52
class EntityShaderManager
{
public:
	//void **vtable;				// 0
	MaterialPtr entity;				// 4
	MaterialPtr entity_alphatest;	// 16
	MaterialPtr entity_static;		// 28
	char filler1[12];				// 40

public:
	EntityShaderManager();
	virtual ~EntityShaderManager();
	virtual void getOverlayColor(Entity &, float) const;
	void _setupShaderParameters(Entity &, const Color &, const Color &, float);
	void _setupShaderParameters(Entity &, const Color &, float);
	void _setupShaderParameters(Entity &, float);
	void _setupShaderParameters(TileSource &, const TilePos &,float);
	void _setupShaderParameters(float, const Color &);
};
