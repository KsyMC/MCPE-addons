#pragma once

#include <string>
#include <vector>
#include "GuiComponent.h"
#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;
class ItemInstance;

// Size : 608
class Gui : public GuiComponent, public AppPlatformListener
{
public:
	static float DropTicks;
	static float GuiScale;
	static float InvGuiScale;

public:
	//void **vtable;					// 64
	char filler1[304];					// 68
	MinecraftClient *mc;				// 372
	char filler2[8];					// 376
	std::string recordPlaying;			// 384
	int recordPlayingUpFor;				// 388
	bool recordIsPlaying;				// 392
	char filler3[7];					// 393
	bool muteChat;						// 400
	char filler4[156];					// 404
	std::string tipMessage;				// 560
	float tipMessageAlpha;				// 564
	float tipMessageLineLength;			// 568
	char filler5[36];					// 572

public:
	Gui(MinecraftClient &);
	void _buildFeedbackCircle();
	void _buildInnerFeedbackCircle(int, float);
	void _buildOuterFeedbackCircle(int, float, float);
	void addMessage(const std::string &, const std::string &, int);
	void clearMessages();
	void cubeSmoothStep(float, float, float);
	void displayChatMessage(const std::string &, const std::string &);
	void displayClientMessage(const std::string &);
	void displayLocalizableMessage(const std::string &, const std::vector<std::string> &);
	void flashSlot(int);
	void floorAlignToScreenPixel(float);
	int getNumSlots();
	void getRectangleArea(int);
	int getSlotIdAt(int, int);
	int getSlotPos(int, int &, int &);
	void handleClick(int, int, int);
	void handleKeyPressed(int);
	void inventoryUpdated();
	bool isInside(int, int);
	int itemCountItoa(char *, int);
	void onAppResumed();
	void onAppSuspended();
	void onConfigChanged(const Config &);
	void onLevelGenerated();
	void postError(int);
	void processLeftShoulder(int);
	void processRightShoulder(int);
	void render(float, bool, int, int);
	void renderBubbles();
	void renderChatMessages(int, int, unsigned int, bool, Font *);
	void renderHearts();
	void renderInteractButton(const std::string &, float, float);
	void renderOnSelectItemNameText(int, Font *, int);
	void renderProgressIndicator(bool, int, int, float);
	void renderSleepAnimation(int, int);
	void renderSlot(int, int, int, float);
	void renderSlotText(const ItemInstance *, float, float, bool, bool, bool);
	void renderToolBar(float, float);
	void renderVignette(float, int, int);
	void setNowPlaying(const std::string &);
	void showPopupNotice(const std::string &);
	void showTipMessage(const std::string &);
	void tick();
	void tickItemDrop();
	void toggleMuteChat();
};
