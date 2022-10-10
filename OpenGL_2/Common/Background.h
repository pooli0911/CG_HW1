#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "../Header/Angel.h"
#include "GameObject.h"
#include "Star.h"
#include "GameOver.h"
#include "Treasure.h"

#define STAR_COUNT 20


class Background
{
public:
	Background(mat4 g_mxModelView, mat4 g_mxProjection);
	~Background();

	float BackSpeed;

	bool _isGameover;
	bool _isTreasure;
	bool _isTreasureGot;

	float treasureSpeed;
	float treasurePosX;
	float treasureTime;
	Treasure* treasure;


	GameOver* gameover;

	Star* star[STAR_COUNT];

	void UpdateBackground(float delta);
	void UpdateStars(float delta);
	void UpdateGameOver(float delta);
	void UpdateTreasure(float delta);

	void GL_Draw();
};

#endif
