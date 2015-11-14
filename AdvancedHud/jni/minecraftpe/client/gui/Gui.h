#pragma once

class Gui
{
public:
	static float InvGuiScale;
	static float GuiScale;

public:
	MinecraftClient		*m_pMC;		// 2648

public:
	void renderToolBar( float, float );
	int getNumSlots();
	void getSlotPos( int, int &, int & );
};
