#pragma once

#include <functional>

class TextureData;
class TickingTexture;
class DynamicTexture;

// Size : 100
class TextureGroup
{
public:
	TextureGroup();
	~TextureGroup();
	void addEmptyTexture(std::string const &, int, int);
	void addManualTexture(TextureData &);
	void addTickingTexture(TickingTexture *);
	void findOrLoadTexture(std::string const &);
	void getInternalNameFor(DynamicTexture);
	void getTexture(DynamicTexture);
	void getTexture(const std::string &);
	TextureData *getTextureData(const std::string &);
	void loadList(const std::string &, std::function<void ()>);
	void loadTexture(const std::string &, bool, bool, bool);
	void reloadAll();
	void removManualTextureData(TextureData &);
	void tick(bool);
	void unloadAll();
	void uploadTexture(const std::string &, TextureData &);
};
