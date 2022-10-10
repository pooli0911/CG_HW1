#ifndef ENEMYSHIP2_H
#define ENEMYSHIP2_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define ENEMYSHIP2_NUM 27  // triangles

class EnemyShip2 : public GameObject
{
public:
	EnemyShip2();
	~EnemyShip2() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif