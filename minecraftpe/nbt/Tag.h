#pragma once

#include <string>

class PrintStream;
class IDataInput;
class IDataOutput;

// Size : 4
class Tag
{
public:
	static void *NullString;

public:
	//void **vtable;	// 0

public:
	Tag(const std::string &);
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput &) const = 0;
	virtual void load(IDataInput &) = 0;
	virtual std::string toString() const = 0;
	virtual char getId() const = 0;
	virtual bool equals(const Tag &) const;
	virtual void print(PrintStream &) const;
	virtual void print(const std::string &, PrintStream &) const;
	virtual void setName(const std::string &);
	virtual std::string getName() const;
	virtual Tag *copy() const = 0;
	std::string getTagName(char);
	static Tag *newTag(char, const std::string &);
	void readNamedTag(IDataInput &, std::string &);
	void writeNamedTag(const std::string &, const Tag &, IDataOutput &);
};
