#ifndef PLAYERSHIP2_H
#define PLAYERSHIP2_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define PLAYERSHIP2_NUM 51  // triangles

class PlayerShip2 : public GameObject
{
public:
	PlayerShip2();
	~PlayerShip2() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
