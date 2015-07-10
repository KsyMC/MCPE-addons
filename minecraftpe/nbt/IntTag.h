#pragma once

#include "Tag.h"

// Size : 8
class IntTag : public Tag
{
public:
	char filler1[4];	// 4

public:
	IntTag(const std::string &);
	IntTag(const std::string &, int);
	virtual ~IntTag();
	virtual void ~IntTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
