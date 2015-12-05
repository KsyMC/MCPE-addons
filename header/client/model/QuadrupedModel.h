#pragma once

#include "Model.h"
#include "ModelPart.h"

// Size : 1024
class QuadrupedModel : public Model
{
public:
	ModelPart head;		// 120
	ModelPart body;		// 248
	ModelPart leg1;		// 376
	ModelPart leg2;		// 504
	ModelPart leg3;		// 632
	ModelPart leg4;		// 760
	ModelPart leg5;		// 888
	int wtf1;			// 1016
	int wtf2;			// 1020

public:
	QuadrupedModel(int, float, int, int);
	virtual ~QuadrupedModel();
	virtual void render(Entity &, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
};
