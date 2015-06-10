#pragma once

#include <vector>
#include <string>
class Model;
class Matrix;

// Size : 128
class ModelPart
{
public:
	float rotationPointX;	// 0
	float rotationPointY;	// 4
	float rotationPointZ;	// 8
	float rotateAngleX;		// 12
	float rotateAngleY;		// 16
	float rotateAngleZ;		// 20
	bool mirror;			// 24
	float offsetX;			// 28
	float offsetY;			// 32
	float offsetZ;			// 36
	std::vector<ModelPart *> childModels;	// 40
	std::string boxName;	// 52
	int textureWidth;		// 56
	int textureHeight;		// 60
	char filler1[4];		// 64
	int textureOffsetX;		// 68
	int textureOffsetY;		// 72
	bool isHidden;			// 76
	char filler2[44];		// 80
	Model *baseModel;		// 124

public:
	ModelPart(ModelPart &&);
	ModelPart(int, int, int, int);
	ModelPart(const std::string &);
	ModelPart(Model *, int, int, int, int);
	~ModelPart();
	void _init(int, int);
	void addBox(float, float, float, int, int, int);
	void addBox(float, float, float, int, int, int, float);
	void addBox(const std::string &, float, float, float, int, int, int);
	void addChild(ModelPart *);
	void compile(float);
	void draw(float);
	void mimic(const ModelPart *);
	void operator=(ModelPart &&);
	void render(float);
	void reset(void);
	void setModel(Model *);
	void setNeverRender(bool);
	void setPos(float, float, float);
	void setTexSize(int, int);
	void texOffs(int, int);
	void translateTo(Matrix &, float);
};
