#pragma once

#include <string>

class TextureData
{
public:
	TextureData(TextureData &&);
	TextureData(int, int, bool);
	TextureData();
	~TextureData();
	void _move(TextureData &);
	void bind(int);
	void clear();
	void load();
	void operator=(TextureData &&);
	void setData(const std::string &);
	void sync();
	void unload();
};