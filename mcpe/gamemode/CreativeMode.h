#ifndef __CREATIVEMODE_H__
#define __CREATIVEMODE_H__

class Minecraft;
class Player;
class Abilities;

class CreativeMode : public GameMode {
public:
	CreativeMode(Minecraft *);
	virtual ~CreativeMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void countinueDestoryBlock(Player *, int, int, int, signed char);
	virtual bool isCreativeType();
	virtual void initAbilities(Abilities &);
	virtual void releaseUsingItem(Player *);
};

#endif