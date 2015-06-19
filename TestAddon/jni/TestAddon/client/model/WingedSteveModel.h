#pragma once

#include "minecraftpe/client/model/Model.h"
#include "minecraftpe/client/model/ModelPart.h"

class WingedSteveModel : public Model
{
public:
	ModelPart leftWingBone1;
	ModelPart rightWingBone1;
	ModelPart rightWingBone4;
	ModelPart leftHorn2;
	ModelPart leftHorn3;
	ModelPart leftHorn4;
	ModelPart leftHorn1;
	ModelPart rightHorn2;
	ModelPart rightHorn3;
	ModelPart rightHorn4;
	ModelPart rightHorn1;
	ModelPart leftShoulderGuard;
	ModelPart leftWingBone3;
	ModelPart rightShoulderGuard;
	ModelPart leftShoulderTeeth1;
	ModelPart leftShoulderTeeth2;
	ModelPart leftShoulderTeeth3;
	ModelPart rightShoulderTeeth1;
	ModelPart rightShoulderTeeth2;
	ModelPart rightShoulderTeeth3;
	ModelPart head;
	ModelPart body;
	ModelPart rightarm;
	ModelPart leftarm;
	ModelPart rightleg;
	ModelPart leftleg;
	ModelPart Shape1;
	ModelPart Shape2;
	ModelPart Shape3;
	ModelPart Shape4;

public:
	WingedSteveModel();
	virtual ~WingedSteveModel();
	virtual void render(Entity &, float, float, float, float, float, float);
	void setRotation(ModelPart *, float, float, float);
};
