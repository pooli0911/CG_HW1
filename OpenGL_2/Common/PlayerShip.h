#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define PLAYERSHIP_NUM 33  // triangles

class PlayerShip : public GameObject
{
public:
	PlayerShip();
	~PlayerShip() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif