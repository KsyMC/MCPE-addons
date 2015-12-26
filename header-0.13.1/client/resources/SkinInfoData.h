#pragma once

#include "shared.h"

class Textures;
class TextureData;

// Size : 8
class SkinInfoData
{
public:
	//void **vtable;	// 0

	SkinInfoData(bool, bool);
	virtual ~SkinInfoData();
	virtual void updateSkin(bool, string const &) = 0;
	virtual TextureData *getTextureData();
	virtual string getData() = 0;
	virtual int getDataLength() = 0;
	virtual bool hasValidTexture() = 0;
	virtual void validataAndResizeSkinData(string &);
	void copySkinPart(string &, int, int, int, int, int, int, int, int);
	bool isSlim();
	void setForceAlpha(string &, int, int, int, int);
	void setNoAlpha(string &, int, int, int, int);
};
