#pragma once

// Size : 16
class Color
{
public:
	static const Color BLACK;
	static const Color BLUE;
	static const Color CYAN;
	static const Color GREEN;
	static const Color GREY;
	static const Color NIL;
	static const Color PURPLE;
	static const Color RED;
	static const Color WHITE;
	static const Color YELLOW;
	static const Color SHADE_DOWN;
	static const Color SHADE_NORTH_SOUTH;
	static const Color SHADE_UP;
	static const Color SHADE_WEST_EAST;

public:
	float red;		// 0
	float green;	// 4
	float blue;		// 8
	float alpha;	// 12

public:
	static Color *fromHSB(float, float, float);
};
