#include "WingedSteveModel.h"

WingedSteveModel::WingedSteveModel()
	: leftWingBone1(this, 0, 32, 64, 64), rightWingBone1(this, 0, 32, 64, 64), rightWingBone4(this, 0, 38, 64, 64),
	  leftHorn2(this, 0, 49, 64, 64), leftHorn3(this, 0, 56, 64, 64), leftHorn4(this, 20, 56, 64, 64), leftHorn1(this, 0, 41, 64, 64),
	  rightHorn2(this, 14, 49, 64, 64), rightHorn3(this, 12, 56, 64, 64), rightHorn4(this, 30, 56, 64, 64), rightHorn1(this, 0, 41, 64, 64),
	  leftShoulderGuard(this, 16, 41, 64, 64), rightShoulderGuard(this, 16, 41, 64, 64),
	  leftWingBone3(this, 0, 38, 64, 64),
	  leftShoulderTeeth1(this, 0, 0, 64, 64), leftShoulderTeeth2(this, 0, 0, 64, 64), leftShoulderTeeth3(this, 0, 0, 64, 64),
	  rightShoulderTeeth1(this, 0, 0, 64, 64), rightShoulderTeeth2(this, 0, 0, 64, 64), rightShoulderTeeth3(this, 0, 0, 64, 64),
	  head(this, 0, 0, 64, 64), body(this, 16, 16, 64, 64),
	  rightarm(this, 40, 16, 64, 64), leftarm(this, 40, 16, 64, 64),
	  rightleg(this, 0, 16, 64, 64), leftleg(this, 0, 16, 64, 64),
	  Shape1(this, 36, 50, 64, 64), Shape2(this, 36, 50, 64, 64), Shape3(this, 36, 50, 64, 64), Shape4(this, 36, 50, 64, 64)
{
	leftWingBone1.addBox(-3, 0, 2, 16, 1, 1);
	leftWingBone1.setPos(-4, 2, 0);
	leftWingBone1.setTexSize(64, 64);
	setRotation(&leftWingBone1, 0, 0, -2.356194);

	rightWingBone1.addBox(-3, -1, 2, 16, 1, 1);
	rightWingBone1.setPos(4, 2, 0);
	rightWingBone1.setTexSize(64, 64);
	setRotation(&rightWingBone1, 0, 0, -0.7853982);

	rightWingBone4.addBox(0, 0, 0, 14, 1, 1);
	rightWingBone4.setPos(13, -8, 1.8);
	rightWingBone4.setTexSize(64, 64);
	setRotation(&rightWingBone4, 0, 0, 0.2443461);

	leftHorn2.addBox(-2, -2, 1, 3, 3, 4);
	leftHorn2.setPos(-3, -7, 3);
	leftHorn2.setTexSize(64, 64);
	setRotation(&leftHorn2, 0.4712389, -0.2268928, 0);

	leftHorn3.addBox(-2, -2, 4, 2, 2, 4);
	leftHorn3.setPos(-3, -7, 3);
	leftHorn3.setTexSize(64, 64);
	setRotation(&leftHorn3, 0.3665191, -0.0872665, 0);

	leftHorn4.addBox(-2, -3, 7, 1, 1, 4);
	leftHorn4.setPos(-3, -7, 3);
	leftHorn4.setTexSize(64, 64);
	setRotation(&leftHorn4, 0.1745329, 0.0349066, 0);

	leftHorn1.addBox(-2, -2, -2, 4, 4, 4);
	leftHorn1.setPos(-3, -7, 3);
	leftHorn1.setTexSize(64, 64);
	setRotation(&leftHorn1, 0.7853982, -0.6981317, 0);

	rightHorn2.addBox(-1, -5, -2, 3, 4, 3);
	rightHorn2.setPos(3, -7, 3);
	rightHorn2.setTexSize(64, 64);
	setRotation(&rightHorn2, -1.064651, 0.0698132, 0);

	rightHorn3.addBox(0, -8, -2, 2, 4, 2);
	rightHorn3.setPos(3, -7, 3);
	rightHorn3.setTexSize(64, 64);
	setRotation(&rightHorn3, -1.239184, 0, 0);

	rightHorn4.addBox(1, -11, -3, 1, 4, 1);
	rightHorn4.setPos(3, -7, 3);
	rightHorn4.setTexSize(64, 64);
	setRotation(&rightHorn4, -1.448623, -0.0872665, 0);

	rightHorn1.addBox(-2, -2, -2, 4, 4, 4);
	rightHorn1.setPos(3, -7, 3);
	rightHorn1.setTexSize(64, 64);
	setRotation(&rightHorn1, -0.7853982, 0.6981317, 0);

	leftShoulderGuard.addBox(-2.5, 0, -2.5, 5, 2, 5);
	leftShoulderGuard.setPos(-8, 0, 0);
	leftShoulderGuard.setTexSize(64, 64);
	setRotation(&leftShoulderGuard, 0, 0, -0.7853982);

	leftWingBone3.addBox(0, -2, 0, 16, 1, 1);
	leftWingBone3.setPos(-13, -9, 2.1);
	leftWingBone3.setTexSize(64, 64);
	setRotation(&leftWingBone3, 0, 0, 2.96706);

	rightShoulderGuard.addBox(-2.5, 0, -2.5, 5, 2, 5);
	rightShoulderGuard.setPos(8, 0, 0);
	rightShoulderGuard.setTexSize(64, 64);
	setRotation(&rightShoulderGuard, 0, 0, 0.7853982);

	leftShoulderTeeth1.addBox(-0.2, 0.5, 1, 2, 1, 1);
	leftShoulderTeeth1.setPos(-11, 3, 0);
	leftShoulderTeeth1.setTexSize(64, 64);
	setRotation(&leftShoulderTeeth1, 0, 0, -0.7853982);

    leftShoulderTeeth2.addBox(-0.2, 0.5, -0.5, 2, 1, 1);
    leftShoulderTeeth2.setPos(-11, 3, 0);
    leftShoulderTeeth2.setTexSize(64, 64);
    setRotation(&leftShoulderTeeth2, 0, 0, -0.7853982);

	leftShoulderTeeth3.addBox(-0.2, 0.5, -2, 2, 1, 1);
	leftShoulderTeeth3.setPos(-11, 3, 0);
	leftShoulderTeeth3.setTexSize(64, 64);
	setRotation(&leftShoulderTeeth3, 0, 0, -0.7853982);

	rightShoulderTeeth1.addBox(-1, -0.2, 1, 2, 1, 1);
	rightShoulderTeeth1.setPos(10, 3, 0);
	rightShoulderTeeth1.setTexSize(64, 64);
	setRotation(&rightShoulderTeeth1, 0, 0, 0.7853982);

	rightShoulderTeeth2.addBox(-1, -0.2, -0.5, 2, 1, 1);
	rightShoulderTeeth2.setPos(10, 3, 0);
	rightShoulderTeeth2.setTexSize(64, 64);
	setRotation(&rightShoulderTeeth2, 0, 0, 0.7853982);

	rightShoulderTeeth3.addBox(-1, -0.2, -2, 2, 1, 1);
	rightShoulderTeeth3.setPos(10, 3, 0);
	rightShoulderTeeth3.setTexSize(64, 64);
	setRotation(&rightShoulderTeeth3, 0, 0, 0.7853982);

	head.addBox(-4, -8, -4, 8, 8, 8);
	head.setPos(0, 0, 0);
	head.setTexSize(64, 64);
	setRotation(&head, 0, 0, 0);

	body.addBox(-4, 0, -2, 8, 12, 4);
	body.setPos(0, 0, 0);
	body.setTexSize(64, 64);
	setRotation(&body, 0, 0, 0);

	rightarm.addBox(-3, -2, -2, 4, 12, 4);
	rightarm.setPos(-5, 2, 0);
	rightarm.setTexSize(64, 64);
	setRotation(&rightarm, 0, 0, 0);

	leftarm.addBox(-1, -2, -2, 4, 12, 4);
	leftarm.setPos(5, 2, 0);
	leftarm.setTexSize(64, 64);
	setRotation(&leftarm, 0, 0, 0);

	rightleg.addBox(-2, 0, -2, 4, 12, 4);
	rightleg.setPos(-2, 12, 0);
	rightleg.setTexSize(64, 64);
	setRotation(&rightleg, 0, 0, 0);

	leftleg.addBox(-2, 0, -2, 4, 12, 4);
	leftleg.setPos(2, 12, 0);
	leftleg.setTexSize(64, 64);
	setRotation(&leftleg, 0, 0, 0);

	Shape1.addBox(-14, -14, 0, 14, 14, 0);
	Shape1.setPos(-13, -7, 3);
	Shape1.setTexSize(64, 64);
	setRotation(&Shape1, -1.570796, 0, -2.429498);

	Shape2.addBox(-14, -14, 0, 14, 14, 0);
	Shape2.setPos(13, -7, 3);
	Shape2.setTexSize(64, 64);
	setRotation(&Shape2, -1.570796, 0, -0.7853982);

	Shape3.addBox(-14, -14, 0, 14, 14, 0);
	Shape3.setPos(13, -7, 3);
	Shape3.setTexSize(64, 64);
	setRotation(&Shape3, -1.570796, 0, -2.96706);

	Shape4.addBox(-14, -14, 0, 14, 14, 0);
	Shape4.setPos(-13, -7, 3);
	Shape4.setTexSize(64, 64);
	setRotation(&Shape4, -1.570796, 0, -0.1745329);
}

WingedSteveModel::~WingedSteveModel()
{

}

void WingedSteveModel::render(Entity &entity, float f, float f1, float f2, float f3, float f4, float f5)
{
	leftWingBone1.render(f5);
	rightWingBone1.render(f5);
	rightWingBone4.render(f5);
	leftHorn2.render(f5);
	leftHorn3.render(f5);
	leftHorn4.render(f5);
	leftHorn1.render(f5);
	rightHorn2.render(f5);
	rightHorn3.render(f5);
	rightHorn4.render(f5);
	rightHorn1.render(f5);
	leftShoulderGuard.render(f5);
	leftWingBone3.render(f5);
	rightShoulderGuard.render(f5);
	leftShoulderTeeth1.render(f5);
	leftShoulderTeeth2.render(f5);
	leftShoulderTeeth3.render(f5);
	rightShoulderTeeth1.render(f5);
	rightShoulderTeeth2.render(f5);
	rightShoulderTeeth3.render(f5);
	head.render(f5);
	body.render(f5);
	rightarm.render(f5);
	leftarm.render(f5);
	rightleg.render(f5);
	leftleg.render(f5);
	Shape1.render(f5);
	Shape2.render(f5);
	Shape3.render(f5);
	Shape4.render(f5);
}

void WingedSteveModel::setRotation(ModelPart *part, float rotateAngleX, float rotateAngleY, float rotateAngleZ)
{
	part->rotateAngleX = rotateAngleX;
	part->rotateAngleY = rotateAngleY;
	part->rotateAngleZ = rotateAngleZ;
}
