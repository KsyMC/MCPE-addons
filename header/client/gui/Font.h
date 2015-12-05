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
	Font(std::string const &, TextureGroup *);
	virtual ~Font();
	virtual void onAppSuspended();
	void _buildChar(std::vector<GlyphQuad> &, int, Color const &, bool, float, float, bool);
	void _containsUnicodeChar(std::string const &);
	void _containsWideChar(std::string const &);
	void _getCharWidth(int, bool);
	void _makeTextObject(std::string const &, Color const &);
	void _scanUnicodeCharacterWidth(int, int, int);
	void clearCache();
	void draw(std::string const &, float, float, Color const &);
	void draw(std::string const &, float, float, Color const &, bool);
	void drawCached(std::string const &, float, float, Color const &, bool, mce::MaterialPtr *);
	void drawShadow(std::string const &, float, float, Color const &);
	void drawTransformed(std::string const &, float, float, Color const &, float, float, bool, float);
	void drawWordWrap(std::string const &, float, float, float, Color const &, bool, bool);
	void getCharWidths();
	void getColorCode(char, float);
	void getLineLength(std::string const &);
	void getParagraphs(std::string const &);
	void hasFormattingCodes(std::string const &);
	void height(std::string const &, int);
	void init();
	void resetFormat(Color const &);
	void splitLinesInBox(std::string const &, int, std::function<void (std::string const &, int)>);
};
