#pragma once

// Size : 16
class Material
{
public:
	enum Type
	{
		//MATERIAL_
	};

public:
	static Material *web, *cake, *portal, *vegetable, *clay, *cactus, *snow, *topsnow, *ice, *coral, *explosive;
	static Material *glass, *decoration, *sand, *fire, *bed, *cloth, *sponge, *replaceable_plant, *plant, *leaves;
	static Material *lava, *water, *metal, *stone, *wood, *dirt, *air;

public:
	bool flammable;				// 0
	bool neverBuildable;		// 1
	bool notAlwaysDestroyable;	// 2
	bool replaceable;			// 3
	char filler1[9];			// 4
	bool notBlockingMotion;		// 12
	char filler2[3];			// 13

public:
	Material(Material::Type, float);
	void setFlammable();
	void setNeverBuildable();
	void setNotAlwaysDestroyable();
	void setNotBlockingMotion();
	void setReplaceable();
	static void initMaterials();
};