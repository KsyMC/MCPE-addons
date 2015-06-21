#pragma once

#include <glm/mat4x4.hpp>

// Size : 64
class Matrix
{
public:
	static Matrix IDENTITY;

public:
	glm::mat4x4 mat;	// 0

public:
	void rotate(float, const Vec3 &);
	void scale(const Vec3 &);
	void setPerspective(float, float, float, float);
	void transform3(Vec3 &, float &);
	void translate(const Vec3 &);
};
