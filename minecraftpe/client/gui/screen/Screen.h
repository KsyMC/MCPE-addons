#pragma once

#include <memory>
#include <vector>
#include "../GuiComponent.h"

namespace Touch
{
	class TButton;
};
namespace Controller
{
	class StickDirection;
};

class MinecraftClient;
class IntRectangle;
class Button;
class TextBox;
class GuiElement;
class MCOEvent;
class MojangConnectionStatus;

// Size : 160
class Screen : public BaseScreen, public GuiComponent
{
public:
	//void *vtable;											// 8
	int width;												// 12
	int height;												// 16
	MinecraftClient *mc;									// 20
	std::vector<std::shared_ptr<Button>> buttonList;		// 24
	std::vector<std::shared_ptr<TextBox>> textboxList;		// 28
	std::vector<std::shared_ptr<Button>> buttonList2;		// 32
	std::vector<std::shared_ptr<GuiElement>> elementList;	// 36
	std::vector<std::shared_ptr<GuiElement>> elementList2;	// 40
	Font *fontObj;											// 108
	MaterialPtr ui_cubemap;									// 148

public:
	Screen(MinecraftClient &);
	virtual ~Screen();
	virtual void _init(int, int);
	virtual void setSize(int, int);
	virtual void onSetKeyboardHeight(float);
	virtual void setAssociatedBlockPos(BlockPos const &);
	virtual void lostFocus();
	virtual void removed();
	virtual void onInternetUpdate();
	virtual void tick(int, int);
	virtual void updateEvents();
	virtual void setupAndRender(UIRenderContext &, int, int, float);
	virtual void handleInputModeChanged(InputMode);
	virtual void handleButtonPress(short);
	virtual void handleButtonRelease(short);
	virtual void handlePointerLocation(short, short);
	virtual void handlePointerPressed(bool);
	virtual void handleDirection(DirectionId, float, float);
	virtual void handleBackEvent(bool);
	virtual void handleTextChar(std::string const &, bool);
	virtual void handleCaretLocation(int);
	virtual void setTextboxText(std::string const &);
	virtual void handleLicenseChanged();
	virtual void handleGazeGestureInput(short, float, float, float);
	virtual void handleDictationEvent();
	virtual void handleCommandEvent(VoiceCommand const &);
	virtual void renderGameBehind() const;
	virtual void closeOnPlayerHurt() const;
	virtual void getWidth();
	virtual void getHeight();
	virtual void toGUICoordinate(int, int, int &, int &);
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void checkForPointerEvent();
	virtual void controllerEvent();
	virtual void tick();
	virtual void renderBackground(int);
	virtual void renderDirtBackground();
	virtual void renderMenuBackground(float);
	virtual void confirmResult(bool, int);
	virtual void supppressedBySubWindow();
	virtual void onTextBoxUpdated(int);
	virtual void onMojangConnectorStatus(MojangConnectionStatus);
	virtual void handleScrollWheel(float);
	virtual void _handlePointerAction(int, int, bool);
	virtual void _updateTabButtonSelection();
	virtual void _buttonClicked(Button &);
	virtual void _guiElementClicked(GuiElement &);
	virtual void _pointerPressed(int, int);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
};
