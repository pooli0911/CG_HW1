#ifndef PLAYERSMALLSHIP_H
#define PLAYERSNALLSHIP_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define PLAYERSMALLSHIP_NUM 3  // triangles

class PlayerSmallShip : public GameObject
{
public:
	PlayerSmallShip();
	~PlayerSmallShip() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif

