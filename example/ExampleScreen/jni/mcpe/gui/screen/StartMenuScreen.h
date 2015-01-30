#ifndef __STARTMENUSCREEN_H__
#define __STARTMENUSCREEN_H__

#include "Screen.h"
#include "../element/TButton.h"

class ImageWithBackground;

namespace Touch {
	class StartMenuScreen : public Screen {
	public:
		typedef void (*InitReal)(StartMenuScreen *);
		typedef void (*SetupPositionsReal)(StartMenuScreen *);
		typedef void (*ButtonClickedReal)(StartMenuScreen *, Button *);

		static InitReal init_real;
		static SetupPositionsReal setupPositions_real;
		static ButtonClickedReal buttonClicked_real;

	public:
		static int currentSplash;

		static Touch::TButton *_exScreenButton;

	public:
		// Size : 496
		Touch::TButton _playButton;				// 200
		Touch::TButton _realmButton;				// 328
		ImageWithBackground *_optionButton;	// 456
		char filler1[36];								// 460

	public:
		StartMenuScreen();
		virtual ~StartMenuScreen();
		virtual void render(int, int, float);
		virtual void init();
		virtual void setupPositions();
		virtual bool handleBackEvent(bool);
		virtual void tick();
		virtual bool isInGameScreen();
		virtual void buttonClicked(Button *);
		virtual void controllerDirectionChanged(int, Controller::StickDirection);

		static void init_hook(StartMenuScreen *);
		static void setupPositions_hook(StartMenuScreen *);
		static void buttonClicked_hook(StartMenuScreen *, Button *);
	};
}

#endif
