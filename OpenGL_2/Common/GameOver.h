#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define GAMEOVER_NUM 264  // triangles

class GameOver : public GameObject
{
public:
	GameOver();
	~GameOver() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif