#pragma once

#include "minecraftpe/MemoryTracker.h"

class Color;

class Tessellator : public MemoryTracker {
public:
	static Tessellator instance;

public:
	Tessellator(MemoryTracker *);
	virtual ~Tessellator();
	void color(const Color &);
	void color(int, int, int, int);
	void vertexUV(float, float, float, float, float);
};
