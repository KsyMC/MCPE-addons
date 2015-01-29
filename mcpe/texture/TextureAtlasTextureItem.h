#ifndef __TEXTUREATASTXTUREITEM_H__
#define __TEXTUREATASTXTUREITEM_H__

class TextureAtlasTextureItem {
public:
	TextureAtlasTextureItem();
	TextureAtlasTextureItem(const TextureAtlasTextureItem &);
	TextureAtlasTextureItem(const std::string &, const std::vector<TextureUVCoordinateSet> &);
	void getName() const;
	int uvCount() const;
	TextureUVCoordinateSet operator[](int) const;
};

#endif
