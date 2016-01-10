#pragma once

class CompoundTag;

class SavedData
{
public:
	virtual ~SavedData();
	virtual void load(const CompoundTag &) = 0;
	virtual void save(CompoundTag &) = 0;
};
