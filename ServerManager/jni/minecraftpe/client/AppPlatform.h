#pragma once

#include <string>

#include "minecraftpe/ValidCharacterFlag.h"

class ImageData;
class ImagePickingCallback;
class UriListener;
class FullscreenMode;
class Vec2;

class AppPlatform
{
public:
	static AppPlatform *mSingleton;

	AppPlatform();
	virtual ~AppPlatform();
	virtual void getDataUrl() const = 0;
	virtual void getImagePath(const std::string &, bool) = 0;
	virtual void loadPNG(ImageData &, const std::string &, bool) = 0;
	virtual void loadTGA(ImageData &, const std::string &);
	virtual void savePNG(ImageData const &, const std::string &);
	virtual void getKeyFromKeyCode(int, int, int);
	virtual void showKeyboard(const std::string &, int, bool, UI::ValidCharacterFlag, const Vec2 &);
	virtual void hideKeyboard();
	virtual void getKeyboardHeight() const;
	virtual void hideMousePointer();
	virtual void showMousePointer();
	virtual void getPointerFocus();
	virtual void setPointerFocus(bool);
	virtual void toggleSimulateTouchWithMouse();
	virtual void captureScreen(int, int, unsigned int, bool);
	virtual void swapBuffers() = 0;
	virtual void getSystemRegion() const = 0;
	virtual void getGraphicsVendor() = 0;
	virtual void getGraphicsRenderer() = 0;
	virtual void getGraphicsVersion() = 0;
	virtual void getGraphicsExtensions() = 0;
	virtual void pickImage(ImagePickingCallback &) = 0;
	virtual void setSleepEnabled(bool);
	virtual void getExternalStoragePath() = 0;
	virtual void getInternalStoragePath() = 0;
	virtual std::string &getUserdataPath() = 0;
	virtual void showDialog(int);
	virtual void createUserInput();
	virtual void getUserInputStatus();
	virtual void getUserInput();
	virtual void _tick();
	virtual void getScreenWidth();
	virtual void getScreenHeight();
	virtual void getPixelsPerMillimeter();
	virtual void updateTextBoxText(const std::string &);
	virtual bool isKeyboardVisible();
	virtual void supportsVibration();
	virtual void vibrate(int);
	virtual void getAssetFileFullPath(const std::string &);
	virtual void readAssetFile(const std::string &);
	virtual void listAssetFilesIn(const std::string &, const std::string &) const;
	virtual void getDateString(int);
	virtual void checkLicense();
	virtual void hasBuyButtonWhenInvalidLicense();
	virtual void uploadPlatformDependentData(int, void *);
	virtual void isNetworkEnabled(bool);
	virtual void isPowerVR();
	virtual void buyGame();
	virtual void finish();
	virtual void launchUri(const std::basic_string<wchar_t> &);
	virtual void useMetadataDrivenScreens() const;
	virtual void useXboxControlHelpers() const;
	virtual void useCenteredGUI() const;
	virtual void useHeightScaleGUI() const;
	virtual void hasIDEProfiler();
	virtual void getPlatformStringVar(int);
	virtual void getApplicationId() = 0;
	virtual void getAvailableMemory();
	virtual void getTotalMemory();
	virtual void getBroadcastAddresses();
	virtual void getModelName();
	virtual void getDeviceId() = 0;
	virtual void createUUID() = 0;
	virtual void isFirstSnoopLaunch() = 0;
	virtual void hasHardwareInformationChanged() = 0;
	virtual void isTablet() = 0;
	virtual void registerUriListener(UriListener &);
	virtual void unregisterUriListener(UriListener &);
	virtual void setFullscreenMode(FullscreenMode);
	virtual void isNetworkThrottled() const;
};
