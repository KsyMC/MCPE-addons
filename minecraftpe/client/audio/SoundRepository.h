#pragma once

#include <string>

class SoundDesc;

// Size : 12
class SoundRepository
{
public:
	std::vector<SoundDesc> list;	// 0

public:
	void add(const std::string &, SoundDesc &);
};
