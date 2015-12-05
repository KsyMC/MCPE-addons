#pragma once

#include "Model.h"
#include "ModelPart.h"

// Size : 1028
class HumanoidModel : public Model
{
public:
	static float HAT_OVERLAY_SCALE;
	static float OVERLAY_SCALE;

public:
	ModelPart head;		// 120
	ModelPart headWear;	// 248
	ModelPart body;		// 376
	ModelPart RightAim;	// 504
	ModelPart LeftAim;	// 632
	ModelPart RightLeg;	// 760
	ModelPart LeftLeg;	// 888
	bool wtf1;			// 1016
	bool wtf2;			// 1017
	int wtf3;			// 1020
	int wtf4;			// 1024

public:
	HumanoidModel(float, float, int, int);
	virtual ~HumanoidModel();
	virtual void render(Entity &, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
};
