#ifndef __SURVIVALMODE_H__
#define __SURVIVALMODE_H__

class SurvivalMode : public GameMode {
public:
	SurvivalMode(Minecraft *);
	virtual ~SurvivalMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void countinueDestoryBlock(Player *, int, int, int, signed char);
	virtual void stopDestroyBlock(Player *, int, int, int, signed char);
	virtual bool canHurtPlayer();
	virtual bool isSurvivalType();
	virtual void initAbilities(Abilities &);
};

#endif
