#ifndef PLAYERSHIP3_H
#define PLAYERSHIP3_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define PLAYERSHIP3_NUM 48  // triangles

class PlayerShip3 : public GameObject
{
public:
	PlayerShip3();
	~PlayerShip3() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
