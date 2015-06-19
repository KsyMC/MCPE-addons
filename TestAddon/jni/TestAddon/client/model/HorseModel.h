#pragma once

#include "minecraftpe/client/model/Model.h"
#include "minecraftpe/client/model/ModelPart.h"

class HorseModel : public Model
{
public:
	ModelPart head;
	ModelPart mouthTop;
	ModelPart mouthBottom;
	ModelPart horseLeftEar;
	ModelPart horseRightEar;
	ModelPart muleLeftEar;
	ModelPart muleRightEar;
	ModelPart neck;
	ModelPart horseFaceRopes;
	ModelPart mane;
	ModelPart body;
	ModelPart tailBase;
	ModelPart tailMiddle;
	ModelPart tailTip;
	ModelPart backLeftLeg;
	ModelPart backLeftShin;
	ModelPart backLeftHoof;
	ModelPart backRightLeg;
	ModelPart backRightShin;
	ModelPart backRightHoof;
	ModelPart frontLeftLeg;
	ModelPart frontLeftShin;
	ModelPart frontLeftHoof;
	ModelPart frontRightLeg;
	ModelPart frontRightShin;
	ModelPart frontRightHoof;
	ModelPart muleLeftChest;
    ModelPart muleRightChest;
    ModelPart horseSaddleBottom;
    ModelPart horseSaddleFront;
    ModelPart horseSaddleBack;
    ModelPart horseLeftSaddleRope;
    ModelPart horseLeftSaddleMetal;
    ModelPart horseRightSaddleRope;
    ModelPart horseRightSaddleMetal;
    ModelPart horseLeftFaceMetal;
    ModelPart horseRightFaceMetal;
    ModelPart horseLeftRein;
    ModelPart horseRightRein;

public:
    HorseModel();
	virtual ~HorseModel();
	virtual void render(Entity &, float, float, float, float, float, float);
	virtual void prepareMobModel(Mob &, float, float, float);
	void setBoxRotation(ModelPart *, float, float, float);
	float updateHorseRotation(float, float, float);
};
