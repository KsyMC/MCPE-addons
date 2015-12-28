#pragma once

#include "shared.h"

// Size : 32
class SkinPack
{
public:
	enum SkinPackType
	{
		DEFAULT, PACK
	};

	string serializableName;	// 0
	string name;				// 4
	string price;				// 8
	bool unlocked;				// 12
	vector<Skin> skins;			// 16
	SkinPackType type;			// 28

	SkinPack(SkinPackType type, string const &serializableName, string name, bool unlocked, initializer_list<Skin> const &skins);

	const string &getSerializableName() const;

	const string &getPrice() const;
	void setPrice(string const &);

	bool isPremiumUnlocked() const;
	void setPremiumUnlocked(bool);

	const string &getName() const;
	const vector<Skin> &getSkins() const;
	SkinPackType getSkinPackType() const;

	bool operator==(SkinPack const &) const;
};
