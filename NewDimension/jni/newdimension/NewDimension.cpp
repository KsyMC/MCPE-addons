#include "NewDimension.h"

NewDimension::NewDimension(Level &level)
	: Dimension(level, DIMENSION_NEW)
{

}

std::string NewDimension::getName() const
{
	return "NewDimension";
}

void NewDimension::init()
{
	Dimension::init();

	setUltraWarm(true);
	setCeiling(true);
}

Color NewDimension::getFogColor(float) const
{
	return Color::GREEN;
}

float NewDimension::getFogDistanceScale() const
{
	return 1;
}
