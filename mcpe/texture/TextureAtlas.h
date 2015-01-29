#ifndef __TXTUREATLAS_H__
#define __TXTUREATLAS_H__

class MinecraftClient;

class TextureAtlas {
public:
	TextureAtlas(const std::string &, TextureFile);
	//void _parseJSON(const Json::Value &); TODO Json
	TextureAtlasTextureItem getTextureItem(const std::string &) const;
	void load(MinecraftClient *);
};

#endif
