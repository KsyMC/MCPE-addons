#pragma once

#include "Tag.h"

// Size : 8
class FloatTag : public Tag
{
public:
	char filler1[4];	// 4

public:
	FloatTag(const std::string &);
	FloatTag(const std::string &, float);
	virtual ~FloatTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
