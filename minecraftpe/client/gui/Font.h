#pragma once

#include <string>
#include <functional>
#include "../AppPlatformListener.h"

class Options;
class Color;
class MaterialPtr;
class Textures;

// Size : 2304
class Font : public AppPlatformListener
{
public:
	Font(Options *, const std::string &, Textures *);
	virtual ~Font();
	virtual void onAppSuspended();
	void _makeTextObject(const std::string &, const Color &);
	void containsUnicodeChar(const std::string &) const;
	void draw(const std::string &, float, float, const Color &);
	void draw(const std::string &, float, float, const Color &, bool);
	void drawCached(const std::string &, float, float, const Color &, bool, MaterialPtr *);
	void drawShadow(const std::string &, float, float, const Color &);
	void drawTransformed(const std::string &, float, float, const Color &, bool, bool);
	void drawWordWrap(const std::string &, float, float, float, const Color &, bool, bool);
	void getCharWidth(int, bool) const;
	void getColorCode(char, float);
	void getLineLength(const std::string &) const;
	void getParagraphs(const std::string &);
	void hasFormattingCodes(const std::string &);
	void height(const std::string &, int);
	void init(Options *);
	void resetFormat(const Color &);
	void setDefaultTexture();
	void setUnicodeTexture(int);
	void splitLinesInBox(const std::string &, int, std::function<void (const std::string &, int)>) const;
};
