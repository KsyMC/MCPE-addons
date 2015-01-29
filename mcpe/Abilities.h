#ifndef __ABILITIES_H__
#define __ABILITIES_H__

class Abilities {
public:
	bool invulnerable;	// 0;
	bool flying;			// 1;
	bool mayfly;			// 2;
	bool instabuild;		// 3;

	void addSaveData(void *);
	void loadSaveData(void *);
};

#endif
