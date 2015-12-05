#pragma once

#include "SkinInfoData.h"

// Size : 16
class ServerSkinInfoData : public SkinInfoData
{
public:
	ServerSkinInfoData(bool);
	virtual ~ServerSkinInfoData();
	virtual void updateSkin(bool, const std::string &);
	virtual TextureData *getTextureData();
	virtual std::string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(std::string &);
};