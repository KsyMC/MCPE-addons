#pragma once

#include "MaterialPtr.h"

class IntRectangle;
class Color;
class Font;

// Size : 1
class ScreenRenderer
{
public:
	static ScreenRenderer *singletonPtr;

public:
	ScreenRenderer();
	void drawRect(int, int, int, int, const Color &, int);
	void drawRect(int, int, int, int, const Color &, const Color &, const Color &, const Color &, int);
	void blit(const IntRectangle &);
	void blit(float, float, int, int, float, float, int, int);
	void blit(int, int, int, int, int, int, int, int, MaterialPtr *);
	void blitRaw(float, float, float, float, float, float, float, float, float);
	void drawString(Font *, const std::string &, int, int, Color const &);
	void drawCenteredString(Font *, const std::string &, int, int, const Color &);
	void fill(float, float, float, float, const Color &) const;
	void fill(int, int, int, int, const Color &) const;
	void fillGradient(float, float, float, float, const Color &, const Color &);
	void fillGradient(int, int, int, int, const Color &, const Color &);
	void fillHorizontalGradient(float, float, float, float, const Color &, const Color &);
	void fillHorizontalGradient(int, int, int, int, const Color &, const Color &);
	ScreenRenderer *singleton();
};
