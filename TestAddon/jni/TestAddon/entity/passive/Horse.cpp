#include "Horse.h"
#include "shared.h"

Horse::Horse(TileSource &tileSource) : Animal(tileSource)
{
	skinPath = "mob/horse_white.png";
	entityRendererId = 8;
}

Horse::~Horse()
{

}

int Horse::getEntityTypeId() const
{
	return 5988;
}

float Horse::getBaseSpeed()
{
	return 0.5;
}

int Horse::getMaxHealth()
{
	return 10;
}

int Horse::getDeathLoot()
{
	return 46;
}

std::string Horse::getHurtSound()
{
	return "mob.cow";
}

std::string Horse::getDeathSound()
{
	return "mob.cowdeath";
}

Entity *Horse::getBreedOffspring(Animal *animal)
{
	return new Horse(*animal->tileSource);
}
