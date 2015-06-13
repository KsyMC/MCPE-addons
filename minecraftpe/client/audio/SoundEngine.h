#pragma once

#include <vector>
#include "SoundDesc.h"
#include "SoundRepository.h"

class Options;
class Minecraft;

// Size : 2636
class SoundEngine
{
public:
	//void **vtable;				// 0
	char filler1[60];				// 4
	Options *options;				// 64
	char filler2[2540];				// 68
	SoundRepository repository;		// 2608
	char filler3[12];				// 2620
	Minecraft *mc;					// 2632

public:
	SoundEngine(float);
	virtual ~SoundEngine();
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	void init(Minecraft *, Options *);
};
