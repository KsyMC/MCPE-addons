#ifndef __MATRIX_H__
#define __MATRIX_H__

struct Vec3;

class Matrix {
public:
	static Matrix IDENTITY;

	// Size : 64
	char filler1[64];

public:
	static void scale(const Vec3 &);
	static void rotate(float, const Vec3 &);
	static void setPerspective(float, float, float, float);
	static void translate(const Vec3 &);
};

#endif
