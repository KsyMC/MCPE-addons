#pragma once

#include "SkinInfoData.h"

// Size : 16
class ClientSkinInfoData : public SkinInfoData
{
public:
	static Textures *textures;

public:
	TextureData *_textureData;	// 8
	bool _validTexture;			// 12

public:
	ClientSkinInfoData(bool);
	virtual ~ClientSkinInfoData();
	virtual void updateSkin(bool, const std::string &);
	virtual TextureData *getTextureData();
	virtual std::string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(std::string &);
};