#pragma once

#include "Tag.h"

// Size : 8
class ByteTag : public Tag
{
public:
	char filler1[4];	// 4

public:
	ByteTag(const std::string &);
	ByteTag(const std::string &, char);
	virtual ~ByteTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
