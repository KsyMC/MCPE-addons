#pragma once

#include "EntityRenderer.h"
#include "ItemRenderChunkType.h"

class Textures;
class ItemInstance;
class TextureUVCoordinateSet;
class Tessellator;

class ItemRenderer : public EntityRenderer
{
public:
	static ItemRenderer *singletonPtr;

public:
	ItemRenderer();
	virtual ~ItemRenderer();
	virtual void render(Entity &, const Vec3 &, float, float);
	void renderGuiItemCorrect(Font *, Textures *, const ItemInstance *, int, int);
	void renderGuiItemDecorations(const ItemInstance *, float, float);
	void renderGuiItemInChunk(ItemRenderChunkType, Textures *, const ItemInstance *, float, float, float, float, float);
	void renderGuiItemNew(Textures *, const ItemInstance *, int, float, float, float, float, float);
	void blit(float, float, float, float, float, float);
	void iconBlit(float, float, const TextureUVCoordinateSet &, float, float, float, float, int, float);
	void fillRect(Tessellator &, float, float, float, float, int);
	int getAtlasPos(const ItemInstance *);
	static ItemRenderer *singleton();
};