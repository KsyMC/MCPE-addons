#pragma once

#include <deque>
#include "Screen.h"

namespace Touch
{
	class HeaderButton;
}

class ImageWithBackground;

// Size : 244
class ChatScreen : public Screen
{
public:
	static std::deque<std::string> sentMessages;

public:
	std::string message;				// 200
	char filler1[4];					// 204
	Touch::HeaderButton *closeButton;	// 208
	Touch::HeaderButton *hideButton;	// 212
	BlankButton *backgroundButton;		// 216
	ImageWithBackground *chatButton;	// 220
	ImageWithBackground *sendButton;	// 224
	char filler2[16];					// 228

public:
	ChatScreen(bool);
	virtual ~ChatScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual void removed();
	virtual bool renderGameBehind();
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual void closeOnPlayerHurt();
	virtual void setTextboxText(const std::string &);
	virtual void buttonClicked(Button *);
	virtual void keyPressed(int);
	virtual void keyboardNewChar(const std::string &, bool);
	void sendChatMessage();
	void drawChatMessages(int);
	void guiMessagesUpdated();
	void updateGuiMessages();
	void updateKeyboardVisibility();
	void updateToggleKeyboardButton();
};
