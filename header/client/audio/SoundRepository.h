#pragma once

#include <string>

class SoundEvent;
class SoundItem;

// Size : 12
class SoundRepository
{
public:
	std::vector<SoundEvent> list;	// 0

public:
	void add(const std::string &, SoundEvent &);
	void get(std::string const &, SoundItem &);
};
