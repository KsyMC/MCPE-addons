#pragma once

#include "MaterialType.h"

// Size : 16
class Material
{
public:
	static Material *mInitialized;
	static Material *mMaterials;

public:
	bool flammable;				// 0
	bool neverBuildable;		// 1
	bool notAlwaysDestroyable;	// 2
	bool replaceable;			// 3
	char filler1[9];			// 4
	bool notBlockingMotion;		// 12
	char filler2[3];			// 13

public:
	Material(MaterialType, Material::Settings, float);
	void setFlammable();
	void setNeverBuildable();
	void setNotAlwaysDestroyable();
	void setNotBlockingMotion();
	void setReplaceable();
	static void initMaterials();
	static void tearDownMaterials();
};
