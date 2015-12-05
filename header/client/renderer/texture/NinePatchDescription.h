#pragma once

class IntRectangle;
class TextureData;

class NinePatchDescription
{
public:
	NinePatchDescription(float, float, float, float, float, float, float, float, float, float, float, float);
	void createSymmetrical(int, int, const IntRectangle &, int, int);
	void transformUVForImage(const TextureData &);
	void transformUVForImageSize(int, int);
};
