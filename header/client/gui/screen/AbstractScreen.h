#pragma once

namespace UI
{
	class GameEventNotification;
};

class AbstractScreen
{
public:
	//void *vtable;		// 0

public:
	virtual ~AbstractScreen();
	virtual void _init(int, int) = 0;
	virtual void setSize(int, int) = 0;
	virtual void onSetKeyboardHeight(float) = 0;
	virtual void setAssociatedBlockPos(BlockPos const &) = 0;
	virtual void lostFocus() = 0;
	virtual void removed() = 0;
	virtual void onInternetUpdate() = 0;
	virtual void onFocusGained();
	virtual void onGameEventNotification(UI::GameEventNotification);
	virtual void tick(int, int) = 0;
	virtual void updateEvents() = 0;
	virtual void setupAndRender(UIRenderContext &, int, int, float) = 0;
	virtual void handleInputModeChanged(InputMode) = 0;
	virtual void handleButtonPress(short) = 0;
	virtual void handleButtonRelease(short) = 0;
	virtual void handlePointerLocation(short, short) = 0;
	virtual void handlePointerPressed(bool) = 0;
	virtual void handleDirection(DirectionId, float, float) = 0;
	virtual void handleBackEvent(bool) = 0;
	virtual void handleTextChar(std::string const &, bool) = 0;
	virtual void handleCaretLocation(int) = 0;
	virtual void setTextboxText(std::string const &) = 0;
	virtual void handleLicenseChanged() = 0;
	virtual void handleGazeGestureInput(short, float, float, float) = 0;
	virtual void handleDictationEvent() = 0;
	virtual void handleCommandEvent(VoiceCommand const &) = 0;
	virtual void renderGameBehind() const = 0;
	virtual void closeOnPlayerHurt() const = 0;
	virtual void isModal() const;
	virtual void isShowingMenu() const;
	virtual void shouldStealMouse() const;
	virtual void getFocusedControl();
	virtual void isWorldViewer() const;
	virtual void exit();
	virtual void isPauseScreen() const;
	virtual void renderWhenTopMost() const;
	virtual void resetDirection();
	virtual void getWidth() = 0;
	virtual void getHeight() = 0;
};
