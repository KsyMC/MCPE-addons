#pragma once

#include "SkinInfoData.h"

// Size : 16
class ClientSkinInfoData : public SkinInfoData
{
public:
	static Textures *mTextures;

	ClientSkinInfoData(bool, bool);
	virtual ~ClientSkinInfoData();
	virtual void updateSkin(bool, const std::string &);
	virtual TextureData *getTextureData();
	virtual std::string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(std::string &);
};
