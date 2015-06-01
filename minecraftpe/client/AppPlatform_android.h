#pragma once

#include "AppPlatform.h"

class ANativeActivity;

class AppPlatform_android : public AppPlatform
{
public:
	AppPlatform_android();
	virtual ~AppPlatform_android();
	virtual void getImagePath(const std::string &, bool);
	virtual void loadPNG(ImageData &, const std::string &, bool);
	virtual void loadTGA(ImageData &, const std::string &);
	virtual void getKeyFromKeyCode(int, int, int);
	virtual void showKeyboard(const std::string &, int, bool);
	virtual void hideKeyboard();
	virtual void swapBuffers();
	virtual void getSystemRegion() const;
	virtual void getGraphicsVendor();
	virtual void getGraphicsRenderer();
	virtual void getGraphicsVersion();
	virtual void getGraphicsExtensions();
	virtual void pickImage(ImagePickingCallback &);
	virtual void getExternalStoragePath();
	virtual void getInternalStoragePath();
	virtual void playSound(const std::string &, float, float);
	virtual void showDialog(int);
	virtual void createUserInput();
	virtual void getUserInputStatus();
	virtual void getUserInput();
	virtual void getScreenWidth();
	virtual void getScreenHeight();
	virtual void getPixelsPerMillimeter();
	virtual void openLoginWindow();
	virtual void updateTextBoxText(const std::string &);
	virtual void getLoginInformation();
	virtual void setLoginInformation(const LoginInformation &);
	virtual void clearSessionIDAndRefreshToken();
	virtual void supportsVibration();
	virtual void vibrate(int);
	virtual void readAssetFile(const std::string &);
	virtual void getDateString(int);
	virtual void checkLicense();
	virtual void hasBuyButtonWhenInvalidLicense();
	virtual void uploadPlatformDependentData(int, void *);
	virtual void isNetworkEnabled(bool);
	virtual void isPowerVR();
	virtual void buyGame();
	virtual void finish();
	virtual void supportsTouchscreen();
	virtual void getPlatformStringVar(int);
	virtual void getApplicationId();
	virtual void getAvailableMemory();
	virtual void getBroadcastAddresses();
	virtual void getModelName();
	virtual void getDeviceId();
	virtual void createUUID();
	virtual void isFirstSnoopLaunch();
	virtual void hasHardwareInformationChanged();
	virtual void isTablet();
	virtual void initWithActivity(ANativeActivity *);
};
