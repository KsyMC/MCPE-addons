#pragma once

#include <string>

// Size : 32
class SoundDesc
{
public:
	void *pcm;		// 0
	int size;		// 4
	int speed;		// 8
	int format;		// 12
	int sampleRate;	// 16
	int i2;			// 20
	void *p2;		// 24
	void *p3;		// 28

public:
	~SoundDesc();
};
