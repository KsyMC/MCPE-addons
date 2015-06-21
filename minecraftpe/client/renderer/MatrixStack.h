#pragma once

class Matrix;

// Size : 40
class MatrixStack
{
public:
	class Ref
	{
	public:
		MatrixStack *stack;	// 0
		Matrix *matrix;		// 4

	public:
		Ref(MatrixStack &, Matrix &);
		Ref(MatrixStack::Ref &&);
		Ref();
		~Ref();
		void _move(MatrixStack::Ref &);
		bool operator=(const Matrix &);
		bool operator=(MatrixStack::Ref &&);
		void release();
	};

public:
	static MatrixStack Projection;
	static MatrixStack View;
	static MatrixStack World;

public:
	char filler1[40];		// 0

public:
	MatrixStack();
	~MatrixStack();
	Matrix *getTop();
	void pop();
	MatrixStack::Ref push();
	MatrixStack::Ref pushIdentity();
};
