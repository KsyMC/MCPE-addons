#pragma once

class CompoundTag;

class SavedData
{
public:
	virtual ~SavedData();
	virtual void load(CompoundTag const &) = 0;
	virtual void save(CompoundTag &) = 0;
};
