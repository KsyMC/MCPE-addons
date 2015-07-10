#pragma once

#include "Tag.h"

// Size : 12
class StringTag : public Tag
{
public:
	char filler1[8];	// 4

public:
	StringTag(const std::string &);
	StringTag(const std::string &, const std::string &);
	virtual ~StringTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
