#ifndef __ARROW_H__
#define __ARROW_H__

#include "Entity.h"

class Arrow : public Entity {
public:
	virtual int getAuxData();
	void shoot(float, float, float, float, float);
};

#endif
