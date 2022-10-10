#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define ENEMYSHIP_NUM 18  // triangles

class EnemyShip : public GameObject
{
public:
	EnemyShip();
	~EnemyShip() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
