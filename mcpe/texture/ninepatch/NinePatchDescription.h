#ifndef __NINEPATCHDESCRIPTION_H__
#define __NINEPATCHDESCRIPTION_H__

struct IntRectangle;

class NinePatchDescription {
public:
	NinePatchDescription(float, float, float, float, float, float, float, float, float, float, float, float);
	void createSymmetrical(int, int, const IntRectangle &, int, int);
};

#endif
