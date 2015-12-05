#pragma once

#include "../json/json.h"

class MinecraftClient;

class TextureAtlas
{
public:
	TextureAtlas(const std::string &, TextureFile);
	void _parseJSON(const Json::Value &);
	TextureAtlasTextureItem getTextureItem(const std::string &) const;
	void load(Minecraft *);
};
