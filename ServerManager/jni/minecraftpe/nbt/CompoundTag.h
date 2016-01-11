#pragma once

#include "NamedTag.h"

class ListTag;
class TagMemoryChunk;

// Size : 32
class CompoundTag : public NamedTag
{
public:
	char filler1[28];	// 4

public:
	CompoundTag();
	CompoundTag(const std::string &);
	CompoundTag(CompoundTag &&);
	virtual ~CompoundTag();
	virtual void write(IDataOutput &) const;
	virtual void load(IDataInput &);
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag &) const;
	virtual void print(const std::string &, PrintStream &) const;
	virtual Tag *copy() const;
	std::unique_ptr<CompoundTag> clone() const;
	bool contains(const std::string &) const;
	bool contains(const std::string &, int) const;
	void get(const std::string &) const;
	void getAllTags(std::vector<Tag *> &) const;
	bool getBoolean(const std::string &) const;
	char getByte(const std::string &) const;
	char *getByteArray(const std::string &) const;
	CompoundTag *getCompound(const std::string &) const;
	float getDouble(const std::string &) const;
	float getFloat(const std::string &) const;
	int getInt(const std::string &) const;
	long long getInt64(const std::string &) const;
	int *getIntArray(const std::string &) const;
	ListTag *getList(const std::string &) const;
	short getShort(const std::string &) const;
	const std::string &getString(const std::string &) const;
	bool isEmpty() const;
	bool operator=(CompoundTag &&);
	void put(const std::string &, std::unique_ptr<Tag>);
	void putBoolean(const std::string &, bool);
	void putByte(const std::string &, char);
	void putByteArray(const std::string &, TagMemoryChunk);
	void putCompound(const std::string &, std::unique_ptr<CompoundTag>);
	void putDouble(const std::string &, float);
	void putFloat(const std::string &, float);
	void putInt(const std::string &, int);
	void putInt64(const std::string &, long long);
	void putShort(const std::string &, short);
	void putString(const std::string &, const std::string &);
};
