#pragma once

#include "SkinInfoData.h"

// Size : 16
class ServerSkinInfoData : public SkinInfoData
{
public:
	ServerSkinInfoData(bool, bool);
	virtual ~ServerSkinInfoData();
	virtual void updateSkin(bool, string const &);
	virtual TextureData *getTextureData();
	virtual string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(string &);
};
