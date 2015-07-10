#pragma once

#include "Tag.h"

// Size : 16
class Int64Tag : public Tag
{
public:
	char filler1[12];	// 4

public:
	Int64Tag(const std::string &);
	Int64Tag(const std::string &, long long);
	virtual ~Int64Tag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
