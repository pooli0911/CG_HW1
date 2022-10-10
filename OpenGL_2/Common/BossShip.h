#ifndef BOSSSHIP_H
#define BOSSSHIP_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define BOSSSHIP_NUM 33

class BossShip : public GameObject
{
public:
	BossShip();
	~BossShip() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
