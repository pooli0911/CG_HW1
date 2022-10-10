#ifndef BOSSSHIP2_H
#define BOSSSHIP2_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define BOSSSHIP2_NUM 93

class BossShip2 : public GameObject
{
public:
	BossShip2();
	~BossShip2() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
