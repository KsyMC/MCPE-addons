#pragma once

#include "GuiElement.h"

class NinePatchDescription;
class Textures;
class Tessellator;

// Size : 508
class NinePatchLayer : public GuiElement
{
public:
	char filler1[400];	// 108

public:
	NinePatchLayer(const NinePatchDescription &, const std::string &, Textures *, float, float);
	virtual ~NinePatchLayer();
	void buildQuad(int);
	void draw(Tessellator &, float, float);
	void exclude(int);
	void getPatchInfo(int, int, float &, float &, float &, float &);
	void setExcluded(int);
	void setSize(float, float);
};
