#pragma once

#include "Tag.h"

// Size : 20
class ListTag : public Tag
{
public:
	char filler1[16];	// 4

public:
	ListTag();
	ListTag(const std::string &);
	virtual ~ListTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual void print(const std::string &, PrintStream &) const;
	virtual Tag *copy() const;
};
