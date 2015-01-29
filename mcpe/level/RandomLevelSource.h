#ifndef __RANDOMLEVELSOURCE_H__
#define __RANDOMLEVELSOURCE_H__

class LevelChunk;

class RandomLevelSource {
public:
	void prepareHeights(int, int, LevelChunk *);
};

#endif
