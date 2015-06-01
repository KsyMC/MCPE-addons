#pragma once

#include <string>

class ClientSkinInfoData;

// Size : 4
class SkinInfo
{
public:
	ClientSkinInfoData *_clientSkinInfoData; // 0

public:
	SkinInfo(bool);
	~SkinInfo();
	void *getData();
	int getDataLength();
	void getTextureData();
	bool hasValidTexture();
	bool isSlim();
	void updateSkin(bool, const std::string &);
};