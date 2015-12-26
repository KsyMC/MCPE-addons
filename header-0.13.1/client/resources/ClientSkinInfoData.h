#pragma once

#include "SkinInfoData.h"

// Size : 16
class ClientSkinInfoData : public SkinInfoData
{
public:
	static Textures *mTextures;

	ClientSkinInfoData(bool, bool);
	virtual ~ClientSkinInfoData();
	virtual void updateSkin(bool, string const &);
	virtual TextureData *getTextureData();
	virtual string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(string &);
};
