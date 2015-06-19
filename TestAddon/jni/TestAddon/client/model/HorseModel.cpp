#include "HorseModel.h"
#include "minecraftpe/entity/Mob.h"
#include "math_.h"

#include <algorithm>
#include <cmath>

HorseModel::HorseModel()
	: body(this, 0, 34, 128, 128),
	  tailBase(this, 44, 0, 128, 128), tailMiddle(this, 38, 7, 128, 128), tailTip(this, 24, 3, 128, 128),
	  backLeftLeg(this, 78, 29, 128, 128), backLeftShin(this, 78, 43, 128, 128), backLeftHoof(this, 78, 51, 128, 128),
	  backRightLeg(this, 96, 29, 128, 128), backRightShin(this, 96, 43, 128, 128), backRightHoof(this, 96, 51, 128, 128),
	  frontLeftLeg(this, 44, 29, 128, 128), frontLeftShin(this, 44, 41, 128, 128), frontLeftHoof(this, 44, 51, 128, 128),
	  frontRightLeg(this, 60, 29, 128, 128), frontRightShin(this, 60, 41, 128, 128), frontRightHoof(this, 60, 51, 128, 128),
	  head(this, 0, 0, 128, 128),
	  mouthTop(this, 24, 18, 128, 128), mouthBottom(this, 24, 27, 128, 128),
	  horseLeftEar(this, 0, 0, 128, 128), horseRightEar(this, 0, 0, 128, 128),
	  muleLeftEar(this, 0, 12, 128, 128), muleRightEar(this, 0, 12, 128, 128),
	  neck(this, 0, 12, 128, 128),
	  muleLeftChest(this, 0, 34, 128, 128), muleRightChest(this, 0, 47, 128, 128),
	  horseSaddleBottom(this, 80, 0, 128, 128), horseSaddleFront(this, 106, 9, 128, 128), horseSaddleBack(this, 80, 9, 128, 128),
	  horseLeftSaddleMetal(this, 74, 0, 128, 128), horseLeftSaddleRope(this, 70, 0, 128, 128), horseRightSaddleMetal(this, 74, 4, 128, 128),
	  horseRightSaddleRope(this, 80, 0, 128, 128), horseLeftFaceMetal(this, 74, 13, 128, 128), horseRightFaceMetal(this, 74, 13, 128, 128),
	  horseLeftRein(this, 44, 10, 128, 128), horseRightRein(this, 44, 5, 128, 128),
	  mane(this, 58, 0, 128, 128),
	  horseFaceRopes(this, 80, 12, 128, 128)
{
	body.addBox(-5.0, -8.0, -19.0, 10, 10, 24);
	body.setPos(0, 11.0, 9.0);

	tailBase.addBox(-1.0, -1.0, 0, 2, 2, 3);
	tailBase.setPos(0, 3.0, 14.0);
	setBoxRotation(&tailBase, -1.134464, 0, 0);

	tailMiddle.addBox(-1.5, -2.0, 3.0, 3, 4, 7);
	tailMiddle.setPos(0, 3.0, 14.0);
	setBoxRotation(&tailMiddle, -1.134464, 0, 0);

	tailTip.addBox(-1.5, -4.5, 9.0, 3, 4, 7);
	tailTip.setPos(0, 3.0, 14.0);
	setBoxRotation(&tailTip, -1.40215, 0, 0);

	backLeftLeg.addBox(-2.5, -2.0, -2.5, 4, 9, 5);
	backLeftLeg.setPos(4.0, 9.0, 11.0);

	backLeftShin.addBox(-2.0, 0, -1.5, 3, 5, 3);
	backLeftShin.setPos(4.0, 16.0, 11.0);

	backLeftHoof.addBox(-2.5, 5.1, -2.0, 4, 3, 4);
	backLeftHoof.setPos(4.0, 16.0, 11.0);

	backRightLeg.addBox(-1.5, -2.0, -2.5, 4, 9, 5);
	backRightLeg.setPos(-4.0, 9.0, 11.0);

	backRightShin.addBox(-1.0, 0, -1.5, 3, 5, 3);
	backRightShin.setPos(-4.0, 16.0, 11.0);

	backRightHoof.addBox(-1.5, 5.1, -2.0, 4, 3, 4);
	backRightHoof.setPos(-4.0, 16.0, 11.0);

	frontLeftLeg.addBox(-1.9, -1.0, -2.1, 3, 8, 4);
	frontLeftLeg.setPos(4.0, 9.0, -8.0);

	frontLeftShin.addBox(-1.9, 0, -1.6, 3, 5, 3);
	frontLeftShin.setPos(4.0, 16.0, -8.0);

	frontLeftHoof.addBox(-2.4, 5.1, -2.1, 4, 3, 4);
	frontLeftHoof.setPos(4.0, 16.0, -8.0);

	frontRightLeg.addBox(-1.1, -1.0, -2.1, 3, 8, 4);
	frontRightLeg.setPos(-4.0, 9.0, -8.0);

	frontRightShin.addBox(-1.1, 0, -1.6, 3, 5, 3);
	frontRightShin.setPos(-4.0, 16.0, -8.0);

	frontRightHoof.addBox(-1.6, 5.1, -2.1, 4, 3, 4);
	frontRightHoof.setPos(-4.0, 16.0, -8.0);

	head.addBox(-2.5, -10, -1.5, 5, 5, 7);
	head.setPos(0, 4.0, -10);
	setBoxRotation(&head, 0.5235988, 0, 0);

	mouthTop.addBox(-2.0, -10, -7.0, 4, 3, 6);
	mouthTop.setPos(0, 3.95, -10);
	setBoxRotation(&mouthTop, 0.5235988, 0, 0);

	mouthBottom.addBox(-2.0, -7.0, -6.5, 4, 2, 5);
	mouthBottom.setPos(0, 4.0, -10);

	setBoxRotation(&mouthBottom, 0.5235988, 0, 0);
	head.addChild(&mouthTop);
	head.addChild(&mouthBottom);

	horseLeftEar.addBox(0.45, -12.0, 4.0, 2, 3, 1);
	horseLeftEar.setPos(0, 4.0, -10);
	setBoxRotation(&horseLeftEar, 0.5235988, 0, 0);

	horseRightEar.addBox(-2.45, -12.0, 4.0, 2, 3, 1);
	horseRightEar.setPos(0, 4.0, -10);
	setBoxRotation(&horseRightEar, 0.5235988, 0, 0);

	muleLeftEar.addBox(-2.0, -16.0, 4.0, 2, 7, 1);
	muleLeftEar.setPos(0, 4.0, -10);
	setBoxRotation(&muleLeftEar, 0.5235988, 0, 0.2617994);

	muleRightEar.addBox(0, -16.0, 4.0, 2, 7, 1);
	muleRightEar.setPos(0, 4.0, -10);
	setBoxRotation(&muleRightEar, 0.5235988, 0, -0.2617994);

	neck.addBox(-2.05, -9.8, -2.0, 4, 14, 8);
	neck.setPos(0, 4.0, -10);
	setBoxRotation(&neck, 0.5235988, 0, 0);

	muleLeftChest.addBox(-3.0, 0, 0, 8, 8, 3);
	muleLeftChest.setPos(-7.5, 3.0, 10);
	setBoxRotation(&muleLeftChest, 0, ((float)3.1416 / 2), 0);

	muleRightChest.addBox(-3.0, 0, 0, 8, 8, 3);
	muleRightChest.setPos(4.5, 3.0, 10);
	setBoxRotation(&muleRightChest, 0, ((float)3.1416 / 2), 0);

	horseSaddleBottom.addBox(-5.0, 0, -3.0, 10, 1, 8);
	horseSaddleBottom.setPos(0, 2.0, 2.0);

	horseSaddleFront.addBox(-1.5, -1.0, -3.0, 3, 1, 2);
	horseSaddleFront.setPos(0, 2.0, 2.0);

	horseSaddleBack.addBox(-4.0, -1.0, 3.0, 8, 1, 2);
	horseSaddleBack.setPos(0, 2.0, 2.0);

	horseLeftSaddleMetal.addBox(-0.5, 6.0, -1.0, 1, 2, 2);
	horseLeftSaddleMetal.setPos(5.0, 3.0, 2.0);

	horseLeftSaddleRope.addBox(-0.5, 0, -0.5, 1, 6, 1);
	horseLeftSaddleRope.setPos(5.0, 3.0, 2.0);

	horseRightSaddleMetal.addBox(-0.5, 6.0, -1.0, 1, 2, 2);
	horseRightSaddleMetal.setPos(-5.0, 3.0, 2.0);

	horseRightSaddleRope.addBox(-0.5, 0, -0.5, 1, 6, 1);
	horseRightSaddleRope.setPos(-5.0, 3.0, 2.0);

	horseLeftFaceMetal.addBox(1.5, -8.0, -4.0, 1, 2, 2);
	horseLeftFaceMetal.setPos(0, 4.0, -10);
	setBoxRotation(&horseLeftFaceMetal, 0.5235988, 0, 0);

	horseRightFaceMetal.addBox(-2.5, -8.0, -4.0, 1, 2, 2);
	horseRightFaceMetal.setPos(0, 4.0, -10);
	setBoxRotation(&horseRightFaceMetal, 0.5235988, 0, 0);

	horseLeftRein.addBox(2.6, -6.0, -6.0, 0, 3, 16);
	horseLeftRein.setPos(0, 4.0, -10);

	horseRightRein.addBox(-2.6, -6.0, -6.0, 0, 3, 16);
	horseRightRein.setPos(0, 4.0, -10);

	mane.addBox(-1.0, -11.5, 5.0, 2, 16, 4);
	mane.setPos(0, 4.0, -10);
	setBoxRotation(&mane, 0.5235988, 0, 0);

	horseFaceRopes.addBox(-2.5, -10.1, -7.0, 5, 5, 12, 0.2);
	horseFaceRopes.setPos(0, 4.0, -10);
	setBoxRotation(&horseFaceRopes, 0.5235988, 0, 0);
}

HorseModel::~HorseModel()
{

}

void HorseModel::render(Entity &entity, float f, float f1, float f2, float f3, float f4, float f5)
{
	if (true)
	{
		horseFaceRopes.render(f5);
		horseSaddleBottom.render(f5);
		horseSaddleFront.render(f5);
		horseSaddleBack.render(f5);
		horseLeftSaddleRope.render(f5);
		horseLeftSaddleMetal.render(f5);
		horseRightSaddleRope.render(f5);
		horseRightSaddleMetal.render(f5);
		horseLeftFaceMetal.render(f5);
		horseRightFaceMetal.render(f5);

		if (true)
		{
			horseLeftRein.render(f5);
			horseRightRein.render(f5);
		}
	}

	backLeftLeg.render(f5);
	backLeftShin.render(f5);
	backLeftHoof.render(f5);
	backRightLeg.render(f5);
	backRightShin.render(f5);
	backRightHoof.render(f5);
	frontLeftLeg.render(f5);
	frontLeftShin.render(f5);
	frontLeftHoof.render(f5);
	frontRightLeg.render(f5);
	frontRightShin.render(f5);
	frontRightHoof.render(f5);

	body.render(f5);
	tailBase.render(f5);
	tailMiddle.render(f5);
	tailTip.render(f5);
	neck.render(f5);
	mane.render(f5);

	if (true)
	{
		muleLeftEar.render(f5);
		muleRightEar.render(f5);
	}
	else
	{
		horseLeftEar.render(f5);
		horseRightEar.render(f5);
	}
	head.render(f5);

	if (true)
	{
		muleLeftChest.render(f5);
		muleRightChest.render(f5);
	}
}

void HorseModel::prepareMobModel(Mob &mob, float f, float f1, float f2)
{
	float f3 = updateHorseRotation(mob.prevRenderYawOffset, mob.renderYawOffset, f2);
	float f4 = updateHorseRotation(mob.prevRotationYawHead, mob.rotationYawHead, f2);
	float f5 = mob.prevRotationPitch + (mob.rotationPitch - mob.prevRotationPitch) * f2;
	float f6 = f4 - f3;
	float f7 = f5 / (180 / (float)PI);

	if (f6 > 20.0)
	{
		f6 = 20.0;
	}

	if (f6 < -20.0)
	{
		f6 = -20.0;
	}

	if (f1 > 0.2)
	{
		f7 += cos(f * 0.4f) * 0.15F * f1;
	}

	//Horse *horse = (Horse *) &mob;
	float f8 = 0;/*entityhorse.getGrassEatingAmount(f2);*/
	float f9 = 0;/*entityhorse.getRearingAmount(f2);*/
	float f10 = 1.0 - f9;
	float f11 = 0;/*entityhorse.func_110201_q(f2);*/
	bool flag = true;/*entityhorse.field_110278_bp != 0;*/
	bool flag1 = true;/*entityhorse.isHorseSaddled();*/
	bool flag2 = false;/*entityhorse.riddenByEntity != null;*/
	float f12 = (float)mob.ticksExisted + f2;
	float f13 = cos(f * 0.6662f + (float)PI);
	float f14 = f13 * 0.8 * f1;
	head.rotationPointY = 4.0;
	head.rotationPointZ = -10.0;
	tailBase.rotationPointY = 3.0;
	tailMiddle.rotationPointZ = 14.0;
	muleRightChest.rotationPointY = 3.0;
	muleRightChest.rotationPointZ = 10.0;
	body.rotateAngleX = 0.0;
	head.rotateAngleX = 0.5235988 + f7;
	head.rotateAngleY = f6 / (180 / (float)PI);
	head.rotateAngleX = f9 * (0.2617994 + f7) + f8 * 2.18166 + (1.0 - std::max(f9, f8)) * head.rotateAngleX;
	head.rotateAngleY = f9 * (f6 / (180 / (float)PI)) + (1.0 - std::max(f9, f8)) * head.rotateAngleY;
	head.rotationPointY = f9 * -6.0 + f8 * 11.0 + (1.0 - std::max(f9, f8)) * head.rotationPointY;
	head.rotationPointZ = f9 * -1.0 + f8 * -10.0 + (1.0 - std::max(f9, f8)) * head.rotationPointZ;
	tailBase.rotationPointY = f9 * 9.0 + f10 * tailBase.rotationPointY;
	tailMiddle.rotationPointZ = f9 * 18.0 + f10 * tailMiddle.rotationPointZ;
	muleRightChest.rotationPointY = f9 * 5.5 + f10 * muleRightChest.rotationPointY;
	muleRightChest.rotationPointZ = f9 * 15.0 + f10 * muleRightChest.rotationPointZ;
	body.rotateAngleX = f9 * -((float)PI / 4) + f10 * body.rotateAngleX;
	horseLeftEar.rotationPointY = head.rotationPointY;
	horseRightEar.rotationPointY = head.rotationPointY;
	muleLeftEar.rotationPointY = head.rotationPointY;
	muleRightEar.rotationPointY = head.rotationPointY;
	neck.rotationPointY = head.rotationPointY;
	mouthTop.rotationPointY = 0.02;
	mouthBottom.rotationPointY = 0.0;
	mane.rotationPointY = head.rotationPointY;
	horseLeftEar.rotationPointZ = head.rotationPointZ;
	horseRightEar.rotationPointZ = head.rotationPointZ;
	muleLeftEar.rotationPointZ = head.rotationPointZ;
	muleRightEar.rotationPointZ = head.rotationPointZ;
	neck.rotationPointZ = head.rotationPointZ;
	mouthTop.rotationPointZ = 0.02 - f11 * 1.0;
	mouthBottom.rotationPointZ = 0.0 + f11 * 1.0;
	mane.rotationPointZ = head.rotationPointZ;
	horseLeftEar.rotateAngleX = head.rotateAngleX;
	horseRightEar.rotateAngleX = head.rotateAngleX;
	muleLeftEar.rotateAngleX = head.rotateAngleX;
	muleRightEar.rotateAngleX = head.rotateAngleX;
	neck.rotateAngleX = head.rotateAngleX;
	mouthTop.rotateAngleX = 0.0 - 0.09424778 * f11;
	mouthBottom.rotateAngleX = 0.0 + 0.15707964 * f11;
	mane.rotateAngleX = head.rotateAngleX;
	horseLeftEar.rotateAngleY = head.rotateAngleY;
	horseRightEar.rotateAngleY = head.rotateAngleY;
	muleLeftEar.rotateAngleY = head.rotateAngleY;
	muleRightEar.rotateAngleY = head.rotateAngleY;
	neck.rotateAngleY = head.rotateAngleY;
	mouthTop.rotateAngleY = 0.0;
	mouthBottom.rotateAngleY = 0.0;
	mane.rotateAngleY = head.rotateAngleY;
	muleLeftChest.rotateAngleX = f14 / 5.0;
	muleRightChest.rotateAngleX = -f14 / 5.0;
	float f15 = ((float)PI / 2);
	float f16 = ((float)PI * 3 / 2);
	float f17 = -1.0471976;
	float f18 = 0.2617994 * f9;
	float f19 = cos(f12 * 0.6f + (float)PI);
	frontLeftLeg.rotationPointY = -2.0 * f9 + 9.0 * f10;
	frontLeftLeg.rotationPointZ = -2.0 * f9 + -8.0 * f10;
	frontRightLeg.rotationPointY = frontLeftLeg.rotationPointY;
	frontRightLeg.rotationPointZ = frontLeftLeg.rotationPointZ;
	backLeftShin.rotationPointY = backLeftLeg.rotationPointY + sin(((float)PI / 2.0f) + f18 + f10 * -f13 * 0.5f * f1) * 7.0;
	backLeftShin.rotationPointZ = backLeftLeg.rotationPointZ + cos(((float)PI * 3.0f / 2.0f) + f18 + f10 * -f13 * 0.5f * f1) * 7.0;
	backRightShin.rotationPointY = backRightLeg.rotationPointY + sin(((float)PI / 2.0f) + f18 + f10 * f13 * 0.5f * f1) * 7.0;
	backRightShin.rotationPointZ = backRightLeg.rotationPointZ + cos(((float)PI * 3.0f / 2.0f) + f18 + f10 * f13 * 0.5f * f1) * 7.0;
	float f20 = (-1.0471976 + f19) * f9 + f14 * f10;
	float f21 = (-1.0471976 + -f19) * f9 + -f14 * f10;
	frontLeftShin.rotationPointY = frontLeftLeg.rotationPointY + sin(((float)PI / 2.0f) + f20) * 7.0;
	frontLeftShin.rotationPointZ = frontLeftLeg.rotationPointZ + cos(((float)PI * 3.0f / 2.0f) + f20) * 7.0;
	frontRightShin.rotationPointY = frontRightLeg.rotationPointY + sin(((float)PI / 2.0f) + f21) * 7.0;
	frontRightShin.rotationPointZ = frontRightLeg.rotationPointZ + cos(((float)PI * 3.0f / 2.0f) + f21) * 7.0;
	backLeftLeg.rotateAngleX = f18 + -f13 * 0.5 * f1 * f10;
	backLeftShin.rotateAngleX = -0.08726646F * f9 + (-f13 * 0.5F * f1 - std::max(0.0F, f13 * 0.5F * f1)) * f10;
	backLeftHoof.rotateAngleX = backLeftShin.rotateAngleX;
	backRightLeg.rotateAngleX = f18 + f13 * 0.5 * f1 * f10;
	backRightShin.rotateAngleX = -0.08726646 * f9 + (f13 * 0.5 * f1 - std::max(0.0, -f13 * 0.5 * f1)) * f10;
	backRightHoof.rotateAngleX = backRightShin.rotateAngleX;
	frontLeftLeg.rotateAngleX = f20;
	frontLeftShin.rotateAngleX = (frontLeftLeg.rotateAngleX + (float)PI * std::max(0.0f, 0.2f + f19 * 0.2f)) * f9 + (f14 + std::max(0.0f, f13 * 0.5f * f1)) * f10;
	frontLeftHoof.rotateAngleX = frontLeftShin.rotateAngleX;
	frontRightLeg.rotateAngleX = f21;
	frontRightShin.rotateAngleX = (frontRightLeg.rotateAngleX + (float)PI * std::max(0.0f, 0.2f - f19 * 0.2f)) * f9 + (-f14 + std::max(0.0f, -f13 * 0.5f * f1)) * f10;
	frontRightHoof.rotateAngleX = frontRightShin.rotateAngleX;
	backLeftHoof.rotationPointY = backLeftShin.rotationPointY;
	backLeftHoof.rotationPointZ = backLeftShin.rotationPointZ;
	backRightHoof.rotationPointY = backRightShin.rotationPointY;
	backRightHoof.rotationPointZ = backRightShin.rotationPointZ;
	frontLeftHoof.rotationPointY = frontLeftShin.rotationPointY;
	frontLeftHoof.rotationPointZ = frontLeftShin.rotationPointZ;
	frontRightHoof.rotationPointY = frontRightShin.rotationPointY;
	frontRightHoof.rotationPointZ = frontRightShin.rotationPointZ;

	if (flag1)
	{
		horseSaddleBottom.rotationPointY = f9 * 0.5 + f10 * 2.0;
		horseSaddleBottom.rotationPointZ = f9 * 11.0 + f10 * 2.0;
		horseSaddleFront.rotationPointY = horseSaddleBottom.rotationPointY;
		horseSaddleBack.rotationPointY = horseSaddleBottom.rotationPointY;
		horseLeftSaddleRope.rotationPointY = horseSaddleBottom.rotationPointY;
		horseRightSaddleRope.rotationPointY = horseSaddleBottom.rotationPointY;
		horseLeftSaddleMetal.rotationPointY = horseSaddleBottom.rotationPointY;
		horseRightSaddleMetal.rotationPointY = horseSaddleBottom.rotationPointY;
		muleLeftChest.rotationPointY = muleRightChest.rotationPointY;
		horseSaddleFront.rotationPointZ = horseSaddleBottom.rotationPointZ;
		horseSaddleBack.rotationPointZ = horseSaddleBottom.rotationPointZ;
		horseLeftSaddleRope.rotationPointZ = horseSaddleBottom.rotationPointZ;
		horseRightSaddleRope.rotationPointZ = horseSaddleBottom.rotationPointZ;
		horseLeftSaddleMetal.rotationPointZ = horseSaddleBottom.rotationPointZ;
		horseRightSaddleMetal.rotationPointZ = horseSaddleBottom.rotationPointZ;
		muleLeftChest.rotationPointZ = muleRightChest.rotationPointZ;
		horseSaddleBottom.rotateAngleX = body.rotateAngleX;
		horseSaddleFront.rotateAngleX = body.rotateAngleX;
		horseSaddleBack.rotateAngleX = body.rotateAngleX;
		horseLeftRein.rotationPointY = head.rotationPointY;
		horseRightRein.rotationPointY = head.rotationPointY;
		horseFaceRopes.rotationPointY = head.rotationPointY;
		horseLeftFaceMetal.rotationPointY = head.rotationPointY;
		horseRightFaceMetal.rotationPointY = head.rotationPointY;
		horseLeftRein.rotationPointZ = head.rotationPointZ;
		horseRightRein.rotationPointZ = head.rotationPointZ;
		horseFaceRopes.rotationPointZ = head.rotationPointZ;
		horseLeftFaceMetal.rotationPointZ = head.rotationPointZ;
		horseRightFaceMetal.rotationPointZ = head.rotationPointZ;
		horseLeftRein.rotateAngleX = f7;
		horseRightRein.rotateAngleX = f7;
		horseFaceRopes.rotateAngleX = head.rotateAngleX;
		horseLeftFaceMetal.rotateAngleX = head.rotateAngleX;
		horseRightFaceMetal.rotateAngleX = head.rotateAngleX;
		horseFaceRopes.rotateAngleY = head.rotateAngleY;
		horseLeftFaceMetal.rotateAngleY = head.rotateAngleY;
		horseLeftRein.rotateAngleY = head.rotateAngleY;
		horseRightFaceMetal.rotateAngleY = head.rotateAngleY;
		horseRightRein.rotateAngleY = head.rotateAngleY;

		if (flag2)
		{
			horseLeftSaddleRope.rotateAngleX = -1.0471976;
			horseLeftSaddleMetal.rotateAngleX = -1.0471976;
			horseRightSaddleRope.rotateAngleX = -1.0471976;
			horseRightSaddleMetal.rotateAngleX = -1.0471976;
			horseLeftSaddleRope.rotateAngleZ = 0;
			horseLeftSaddleMetal.rotateAngleZ = 0;
			horseRightSaddleRope.rotateAngleZ = 0;
			horseRightSaddleMetal.rotateAngleZ = 0;
		}
		else
		{
			horseLeftSaddleRope.rotateAngleX = f14 / 3.0;
			horseLeftSaddleMetal.rotateAngleX = f14 / 3.0;
			horseRightSaddleRope.rotateAngleX = f14 / 3.0;
			horseRightSaddleMetal.rotateAngleX = f14 / 3.0;
			horseLeftSaddleRope.rotateAngleZ = f14 / 5.0;
			horseLeftSaddleMetal.rotateAngleZ = f14 / 5.0;
			horseRightSaddleRope.rotateAngleZ = -f14 / 5.0;
			horseRightSaddleMetal.rotateAngleZ = -f14 / 5.0;
		}
	}

	f15 = -1.3089 + f1 * 1.5;

	if (f15 > 0)
	{
		f15 = 0;
	}

	if (flag)
	{
		tailBase.rotateAngleY = cos(f12 * 0.7f);
		f15 = 0;
	}
	else
	{
		tailBase.rotateAngleY = 0;
	}

	tailMiddle.rotateAngleY = tailBase.rotateAngleY;
	tailTip.rotateAngleY = tailBase.rotateAngleY;
	tailMiddle.rotationPointY = tailBase.rotationPointY;
	tailTip.rotationPointY = tailBase.rotationPointY;
	tailMiddle.rotationPointZ = tailBase.rotationPointZ;
	tailTip.rotationPointZ = tailBase.rotationPointZ;
	tailBase.rotateAngleX = f15;
	tailMiddle.rotateAngleX = f15;
	tailTip.rotateAngleX = -0.2618 + f15;
}

void HorseModel::setBoxRotation(ModelPart *part, float rotateAngleX, float rotateAngleY, float rotateAngleZ)
{
	part->rotateAngleX = rotateAngleX;
	part->rotateAngleY = rotateAngleY;
	part->rotateAngleZ = rotateAngleZ;
}

float HorseModel::updateHorseRotation(float f, float f1, float f2)
{
	float f3;

	for (f3 = f1 - f; f3 < -180.0f; f3 += 360.0f)
	{
		;
	}

	while (f3 >= 180.0f)
	{
		f3 -= 360.0f;
	}

	return f + f2 * f3;
}
