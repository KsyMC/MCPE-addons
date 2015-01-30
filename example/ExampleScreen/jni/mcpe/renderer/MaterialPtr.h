#ifndef __MATERIALPTR_H__
#define __MATERIALPTR_H__

#include "../../shared.h"

class RenderMaterialGroup;

class MaterialPtr {
public:
	char filler1[12];	// 0

	MaterialPtr(MaterialPtr &&);
	MaterialPtr(RenderMaterialGroup &, const std::string &);
	MaterialPtr();
};

#endif