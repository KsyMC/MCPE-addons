#pragma once

#include "../client/AppPlatformListener.h"
#include "ChunkSource.h"

class ChunkCache : public ChunkSource, public AppPlatformListener
{
public:
	ChunkCache(ChunkSource *);
};
