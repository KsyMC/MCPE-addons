#pragma once

#include "../MemoryTracker.h"

class Color;
class PrimitiveMode;
class MaterialPtr;

class Tessellator : public MemoryTracker
{
public:
	static Tessellator instance;

public:
	Tessellator(MemoryTracker *);
	virtual ~Tessellator();
	virtual void getStats() const;
	void _allocateIndices(int);
	void _tex(const Vec2 &, int);
	void addOffset(const Vec3 &);
	void addOffset(float, float, float);
	void begin(PrimitiveMode, int);
	void begin(int);
	void beginIndices(int);
	void color(const Color &);
	void color(float, float, float, float);
	void color(int);
	void color(int, int);
	void color(int, int, int, int);
	void color(unsigned char, unsigned char, unsigned char, unsigned char);
	void colorABGR(int);
	void draw(const MaterialPtr &);
	void enableColor();
	void end(const char *, bool);
	void getColor();
	void getPolygonCount() const;
	void init();
	void noColor();
	void normal(const Vec3 &);
	void normal(float, float, float);
	void quad(unsigned int, bool);
	void quad(unsigned int, unsigned int, unsigned int, unsigned int);
	void resetScale();
	void resetTilt();
	void rotationOffset(float, const Vec3 &);
	void scale2d(float, float);
	void scale3d(float, float, float);
	void setOffset(const Vec3 &);
	void setOffset(float, float, float);
	void tex(const Vec2 &);
	void tex(float, float);
	void tex1(const Vec2 &);
	void tex1(float, float);
	void tilt();
	void triangle(unsigned int, unsigned int, unsigned int);
	void trim();
	void vertex(const Vec3 &);
	void vertex(float, float, float);
	void vertexUV(const Vec3 &, float, float);
	void vertexUV(float, float, float, float, float);
	void voidBeginAndEndCalls(bool);
};
