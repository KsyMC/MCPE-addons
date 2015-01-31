#include "../../../shared.h"
#include "StartMenuScreen.h"
#include "ExampleScreen.h"
#include "../element/TButton.h"
#include "../element/ImageWithBackground.h"
#include "../../MinecraftClient.h"

// initialize static elements
Touch::StartMenuScreen::InitReal Touch::StartMenuScreen::init_real = NULL;
Touch::StartMenuScreen::SetupPositionsReal Touch::StartMenuScreen::setupPositions_real = NULL;
Touch::StartMenuScreen::ButtonClickedReal Touch::StartMenuScreen::buttonClicked_real = NULL;
Touch::TButton *Touch::StartMenuScreen::_exScreenButton = NULL;

// Hooked function of init()
void Touch::StartMenuScreen::init_hook(Touch::StartMenuScreen *screen) {
	// Has _exScreenButton initialized? if not:
	if(!_exScreenButton) {
		_exScreenButton = new Touch::TButton(0, "Example Screen", NULL, false);
		_exScreenButton->init(screen->_minecraftClient);
	}

	// Add button.
	screen->_vecBtn.emplace_back(_exScreenButton);

	// Call real init() function.
	Touch::StartMenuScreen::init_real(screen);
}

// Hooked function of setupPositions()
void Touch::StartMenuScreen::setupPositions_hook(Touch::StartMenuScreen *screen) {
	// Call real setupPositions() function.
	Touch::StartMenuScreen::setupPositions_real(screen);

	// Get an option button.
	ImageWithBackground *optionButton = screen->_optionButton;

	// Put the button on the option button.
	_exScreenButton->_x = optionButton->_x;
	_exScreenButton->_y = optionButton->_y - optionButton->_height - 10;
	_exScreenButton->_width = optionButton->_width;
	_exScreenButton->_height = optionButton->_height;
}

// Hooked function of buttonClicked().
void Touch::StartMenuScreen::buttonClicked_hook(Touch::StartMenuScreen *screen, Button *button) {
	// Call real buttonClicked() function.
	Touch::StartMenuScreen::buttonClicked_real(screen, button);

	// If the clicked button is what we added:
	if(button->_buttonId == _exScreenButton->_buttonId) {
		// Move to ExampleScreen!
		screen->_minecraftClient->setScreen(new ExampleScreen());
	}
}
