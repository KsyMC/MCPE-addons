#pragma once

#include "Tag.h"

// Size : 16
class DoubleTag : public Tag
{
public:
	char filler1[12];	// 4

public:
	DoubleTag(const std::string &);
	DoubleTag(const std::string &, double);
	virtual ~DoubleTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
