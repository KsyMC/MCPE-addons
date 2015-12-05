#pragma once

#include <string>
#include <vector>
#include "GuiComponent.h"
#include "../settings/IConfigListener.h"
#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;
class ItemInstance;

// Size : 3040
class Gui : public GuiComponent, public IConfigListener, public AppPlatformListener
{
public:
	static float DropTicks;
	static float GuiScale;
	static float InvGuiScale;
	static float BUTTONS_TRANSPARENCY;

public:
	//void **vtable;					// 64
	char filler1[2520];					// 68
	MinecraftClient *mc;				// 2588

public:
	Gui(MinecraftClient &);
	virtual ~Gui();
	virtual void onAppSuspended();
	virtual void onConfigChanged(Config const &);
	void _buildFeedbackCircle();
	void _buildInnerFeedbackCircle(int, float);
	void _buildOuterFeedbackCircle(int, float, float);
	void _cubeSmoothStep(float, float, float);
	void _renderPortalOverlay(float, int, int);
	void _renderSlot(int, int, int, float);
	void _renderVignette(float, int, int);
	void _tickItemDrop();
	void _touchEnabledOrHolographic();
	void _updateHudPositions();
	void addMessage(std::string const &, std::string const &, int, bool);
	void clearMessages();
	void displayChatMessage(std::string const &, std::string const &);
	void displayClientMessage(std::string const &);
	void displayLocalizableMessage(std::string const &, std::vector<std::string> const &);
	void displaySystemMessage(std::string const &);
	void drawRectangleArea(Tessellator &, RectangleArea const *, int, int, float);
	void drawRectangleArea(Tessellator &, RectangleArea const *, int, int, float, float);
	void flashSlot(int);
	void floorAlignToScreenPixel(float);
	void forceMuteChat();
	void getGuiScale();
	void getInvGuiScale();
	void getMessageList();
	int getNumSlots();
	void getSlotIdAt(int, int);
	void getSlotPos(int, int &, int &);
	void handleClick();
	void inventoryUpdated();
	bool isInside(int, int);
	bool isMuteChat();
	bool itemCountItoa(char *, int);
	void onLevelGenerated();
	void onMobEffectsChanged(MobEffectsLayout const &);
	void postError(int);
	void render(float, bool, int, int);
	void renderBubbles();
	void renderChatMessages(int, int, uint, bool, Font *);
	void renderCursor(float, float);
	void renderExperience();
	void renderHearts();
	void renderHunger();
	void renderOnSelectItemNameText(int, Font *, int);
	void renderProgressIndicator(int, int, float);
	void renderSleepAnimation(int, int);
	void renderSlotText(ItemInstance const *, float, float, bool, bool, bool, bool);
	void renderToolBar(float, float);
	void setGuiScale(float);
	void setIsChatting(bool);
	void setNowPlaying(std::string const &);
	void setShowProgress(bool);
	void setTouchToolbarArea(RectangleArea const &);
	void showPopupNotice(std::string const &, std::string const &);
	void showTipMessage(std::string const &);
	void tick();
	void toggleMuteChat();
	void updatePointerLocation(short, short);
	void wasToolbarClicked();
};
