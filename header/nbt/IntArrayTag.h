#pragma once

#include "Tag.h"

// Size : 12
class IntArrayTag : public Tag
{
public:
	char filler1[8];	// 4

public:
	IntArrayTag(const std::string &);
	IntArrayTag(const std::string &, TagMemoryChunk);
	virtual ~IntArrayTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
