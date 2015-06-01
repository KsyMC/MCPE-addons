#pragma once

#include <functional>

class Options;
class AppPlatform;
class TextureData;
class TickingTexture;
class DynamicTexture;

// Size : 100
class Textures
{
public:
	Textures(Options *, AppPlatform *);
	~Textures();
	void addManualTexture(TextureData &);
	void addTickingTexture(TickingTexture *);
	void bindDynamicTexture(DynamicTexture, int);
	void bindTexture(const std::string &, int, bool);
	void clear();
	void getDynimicTextureData(DynamicTexture);
	void getDynimicTextureDataModify(DynamicTexture);
	TextureData *getTextureData(const std::string &);
	void loadDynamicTextures();
	void loadList(const std::string &, std::function<void (void)>);
	void loadTexture(const std::string &, bool, bool, bool);
	void reloadAll();
	void removManualTextureData(TextureData &);
	void tick(bool);
	void unloadAll();
	void uploadTexture(const std::string &, TextureData &);
};