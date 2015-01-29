#ifndef __MATRIXSTACK_H__
#define __MATRIXSTACK_H__

struct Vec3;

class MatrixStack {
public:
	class Ref {
		Ref();
		~Ref();
	};

public:
	static MatrixStack World;
	static MatrixStack Projection;
	static MatrixStack View;

public:
	// Size : 39
	char filler1[39];		// 0

public:
	MatrixStack();
	~MatrixStack();
	void push();
	void pop();
	void scale(const Vec3 &);
	void pushIdentity();
};

#endif