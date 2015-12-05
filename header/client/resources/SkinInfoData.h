#pragma once

#include <string>

class Textures;
class TextureData;

// Size : 8
class SkinInfoData
{
public:
	static Textures *textures;

public:
	//void **vtable;	// 0
	bool wtf;			// 4

public:
	SkinInfoData(bool);
	virtual ~SkinInfoData();
	virtual void updateSkin(bool, const std::string &) = 0;
	virtual TextureData *getTextureData();
	virtual std::string getData() = 0;
	virtual int getDataLength() = 0;
	virtual bool hasValidTexture() = 0;
	virtual void validataAndResizeSkinData(std::string &);
	void copySkinPart(std::string &, int, int, int, int, int, int, int, int);
	bool isSlim();
	void setForceAlpha(std::string &, int, int, int, int);
	void setNoAlpha(std::string &, int, int, int, int);
};