#pragma once

#include "Tag.h"

// Size : 8
class ShortTag : public Tag
{
public:
	ShortTag(const std::string &);
	ShortTag(const std::string &, short);
	virtual ~ShortTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
