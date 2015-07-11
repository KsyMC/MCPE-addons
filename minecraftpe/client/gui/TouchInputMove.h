#pragma once

#include "MoveInput.h"
#include "GuiComponent.h"
#include "RectangleArea.h"
#include "TouchAreaModel.h"

class MinecraftClient;
class Options;
class Tessellator;

class TouchInputMove : public MoveInput, public GuiComponent
{
public:
	static float BUTTONS_TRANSPARENCY;

public:
	//void **vtable;			// 20
	RectangleArea moveArea;		// 84
	char filler1[8];			// 104
	Options *options;			// 112
	bool jumping;				// 116
	bool forward;				// 117
	bool backward;				// 118
	bool flying;				// 119
	TouchAreaModel areaModel;	// 120
	MinecraftClient *mc;		// 136
	RectangleArea leftArea;		// 140
	RectangleArea rightArea;	// 160
	RectangleArea upArea;		// 180
	RectangleArea downArea;		// 200
	RectangleArea area6;		// 220
	RectangleArea chatArea;		// 240
	RectangleArea area8;		// 260
	RectangleArea interactArea;	// 280
	RectangleArea jumpArea;		// 300
	RectangleArea leftTopArea;	// 320
	RectangleArea rightTopArea;	// 340
	RectangleArea area13;		// 380
	char filler3[40];			// 400
	bool b4;					// 440
	char filler4[4];			// 444
	bool upDown;				// 448
	bool downDown;				// 449
	bool leftDown;				// 450
	bool rightDown;				// 451
	bool jumpDown;				// 452
	bool b8;					// 453
	bool chatDown;				// 454
	bool b10;					// 455

public:
	TouchInputMove(MinecraftClient *, Options *);
	virtual ~TouchInputMove();
	virtual void tick(Player &);
	virtual void render(float);
	virtual void setKey(int, bool);
	virtual void releaseAllKeys();
	virtual void onConfigChanged(const Config &);
	virtual void allowPicking(float, float);
	static void drawRectangleArea(Tessellator &, RectangleArea &, int, int, float);
	static void drawRectangleArea(Tessellator &, RectangleArea &, int, int, float, float);
	bool canInteract();
	void clear();
	RectangleArea getPauseRectangleArea();
	RectangleArea getRectangleArea();
	void interactWithEntity();
	void interactWithItem();
	bool isButtonDown(int);
	void rebuild();
};
