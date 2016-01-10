#pragma once

#include "Tag.h"

// Size : 4
class EndTag : public Tag
{
public:
	virtual ~EndTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual Tag *copy() const;
};
