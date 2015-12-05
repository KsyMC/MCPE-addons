#pragma once

#include "../../MemoryTracker.h"

class TextureTessellator : public MemoryTracker
{
public:
	TextureTessellator(Tessellator &);
	virtual ~TextureTessellator();
	virtual void getStats() const;
};
