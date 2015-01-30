#ifndef __COLOR_H__
#define __COLOR_H__

typedef struct Color {
	static Color BLACK;
	static Color BLUE;
	static Color CYAN;
	static Color GREEN;
	static Color GREY;
	static Color NIL;
	static Color PURPLE;
	static Color RED;
	static Color WHITE;
	static Color YELLOW;
	static Color SHADE_DOWN;
	static Color SHADE_NORTH_SOUTH;
	static Color SHADE_UP;
	static Color SHADE_WEST_EAST;

	float _red;		// 0
	float _green;	// 4
	float _blue;	// 8
	float _alpha;	// 12

	Color *fromHSB(float, float, float);
} COLOR;

#endif