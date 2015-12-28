#pragma once

#include "shared.h"

class SkinPack;

// Size : 24
class Skin
{
public:
	enum SkinType
	{
		DEFAULT, FREE, PAID
	};

	SkinPack *pack;			// 0
	string serializable;	// 4
	string name;			// 8
	string geometryName;	// 12
	string path;			// 16
	SkinType type;			// 20

	Skin(string const &serializable, string const &name, string const &geometryName, string const &path, SkinType type);

	SkinPack *getSkinPack() const;
	void setSkinPack(SkinPack *);

	const string &getSerializable() const;
	const string &getName() const;
	const string &getGeometryName() const;
	const string &getPath() const;

	bool premiumLocked() const;
	bool isCustomSkin() const;

	bool operator==(Skin const &) const;
};
