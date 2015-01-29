#ifndef __TESSELLATOR_H__
#define __TESSELLATOR_H__

struct Color;

class Tessellator /*: public MemoryTracker*/ {
public:
	static Tessellator instance;

	//void** vtable;		// 0

public:
	void color(const Color &);
	void color(int, int, int, int);
	void vertexUV(float, float, float, float, float);
};

#endif
