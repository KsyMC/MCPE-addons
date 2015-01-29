#ifndef __SCREENCHOOSER_H__
#define __SCREENCHOOSER_H__

enum ScreenId {
	SCREEN_GAME,
	SCREEN_MAIN,
	SCREEN_PAUSE1,
	SCREEN_PAUSE2,
	SCREEN_INVENTORY,
	SCREEN_CHAT1,
	SCREEN_CHAT2,
	SCREEN_EXIT1,
	SCREEN_EXIT2
};

class Screen;

class ScreenChooser {
public:
	Screen *createScreen(ScreenId);
	void setScreen(ScreenId);
};

#endif
