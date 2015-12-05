#pragma once

// Size : 20
class RectangleArea
{
public:
	//void **vtable;	// 0
	float xLeft;		// 4
	float xRight;		// 8
	float yTop;			// 12
	float yBottom;		// 16

public:
	RectangleArea();
	RectangleArea(float, float, float, float);
	virtual ~RectangleArea();
	virtual void isInside(float, float) const;
	virtual void centerX() const;
	virtual void centerY() const;
};
