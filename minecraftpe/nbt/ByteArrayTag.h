#pragma once

#include "Tag.h"

// Size : 12
class ByteArrayTag : public Tag
{
public:
	char filler1[8];	// 4

public:
	ByteArrayTag(const std::string &);
	ByteArrayTag(const std::string &, TagMemoryChunk);
	virtual ~ByteArrayTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
