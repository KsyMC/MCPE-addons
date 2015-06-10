#pragma once

class EntityPos
{
public:
	float posX;			// 0
	float posY;			// 4
	float posZ;			// 8
	float rotationYaw;	// 12
	float rotationPitch;// 16
	bool teleport;		// 20
	bool angle;			// 21
};
