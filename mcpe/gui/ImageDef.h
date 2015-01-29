#ifndef __IMAGEDEF_H__
#define __IMAGEDEF_H__

typedef struct ImageDef {
	std::string _textureName;		// 0
	int	_x;								// 4
	int	_y;								// 8
	float _width;						// 12
	float _height;					// 16
	IntRectangle _intRectangle;	// 20
	bool _crop;						// 36
} IMAGEDEF;

#endif
