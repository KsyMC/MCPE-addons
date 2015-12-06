#pragma once

#include "minecraftpe/Dimension.h"

class NewDimension : public Dimension
{
public:
	NewDimension(Level &level);

	virtual std::string getName() const;

	virtual void init();

	virtual Color getFogColor(float) const;
	virtual float getFogDistanceScale() const;
};
