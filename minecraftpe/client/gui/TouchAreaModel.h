#pragma once

class RectangleArea;
class MouseAction;

// Size : 16
class TouchAreaModel
{
public:
	//void **vtable;	// 0
	char filler1[12];	// 4

public:
	TouchAreaModel();
	virtual ~TouchAreaModel();
	virtual int getPointerId(const MouseAction &);
	virtual int getPointerId(int, int, int);
	void addArea(int, RectangleArea &);
	void clear();
};
