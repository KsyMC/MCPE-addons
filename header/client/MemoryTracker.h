#pragma once

#include <string>

class MemoryTracker
{
public:
	//void** vtable;	// 0

public:
	MemoryTracker(const std::string &, MemoryTracker *);
	virtual ~MemoryTracker();
	virtual void getStats() const = 0;
};
