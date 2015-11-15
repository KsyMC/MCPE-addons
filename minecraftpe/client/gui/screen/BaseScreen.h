#pragma once

#include "AbstractScreen.h"

class BaseScreen : public AbstractScreen
{
public:
	virtual ~BaseScreen();
	virtual void toGUICoordinate(int, int, int &, int &);
	void cleanupForRendering();
	void setScreenSetupCleanup(std::unique_ptr<AbstractScreenSetupCleanupStrategy>);
	void setupForRendering(float);
};
