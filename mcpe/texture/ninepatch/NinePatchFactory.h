#ifndef __NINEPATHPACTORY_H__
#define __NINEPATHPACTORY_H__

class Textures;
class NinePatchLayer;
struct IntRectangle;

class NinePatchFactory {
public:
	Textures *_textures;		// 0
	std::string _textureFile;	// 4
	char filler1[8];			// 8

public:
	NinePatchFactory(Textures *, const std::string &);
	NinePatchLayer *createSymmetrical(const IntRectangle &, int, int, float, float);
};

#endif
