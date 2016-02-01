#pragma once

#include <memory>

#include "minecraftpe/material/MaterialType.h"

class Color;

class Material {
public:
	MaterialType type;	// 0
	bool flammable;	// 4
	bool neverBuildable;	// 5
	bool alwaysDestroyable; // 6
	bool replaceable;	// 7
	int liquid;	// 8; wtf? supposed to be a boolean.
	float translucency;	// 12
	bool blocksMotion;	// 16
	bool solid;	// 17
	bool superhot;	// 18
public:
	class Settings;
	
	static Material* mInitialized[];
	static Material* mMaterials[];
	
	Material(MaterialType, Material::Settings, float);
	virtual ~Material();
	void _setFlammable();
	void _setMapColor(const Color&);
	void _setNeverBuildable();
	void _setNotAlwaysDestroyable();
	void _setNotBlockingMotion();
	void _setNotSolid();
	void _setReplaceable();
	void _setSuperHot();
	static void _setupSurfaceMaterials();
	static void addMaterial(std::unique_ptr<Material>);
	bool getBlocksMotion() const;
	const Color& getColor() const;
	static Material getMaterial(MaterialType);
	float getTranslucency() const;
	static void initMaterials();
	bool isAlwaysDestroyable() const;
	bool isFlammable() const;
	bool isLiquid() const;
	bool isNeverBuildable() const;
	bool isReplaceable() const;
	bool isSolid() const;
	bool isSolidBlocking() const;
	bool isSuperHot() const;
	bool isType(MaterialType) const;
	bool operator!=(const Material&) const;
	bool operator==(const Material&) const;
	static void teardownMaterials();
};