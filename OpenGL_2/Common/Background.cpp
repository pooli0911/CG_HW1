#include "Background.h"

Background::Background(mat4 g_mxModelView, mat4 g_mxProjection)
{
	BackSpeed = 5.0f;

	treasureSpeed = 8.0f;

	treasureTime = 0;

	_isGameover = false;
	_isTreasure = false;
	_isTreasureGot = true;

	for (int i = 0; i < STAR_COUNT; i++) {
		vec4 vColor = vec4(0.2f, 0.2f, 0.2f, 0.0f);
		star[i] = new Star();
		star[i]->setColor(vColor);
		star[i]->setShader(g_mxModelView, g_mxProjection);
	}
	vec4 vColor = vec4(1.0f, 1.0f, 1.0f, 0.0f);
	gameover = new GameOver();
	gameover->setColor(vColor);
	gameover->setShader(g_mxModelView, g_mxProjection);

	vec4 vColor2 = vec4(1.0f, 1.0f, 0.0f, 1.0f);
	treasure = new Treasure;
	treasure->setColor(vColor2);
	treasure->setShader(g_mxModelView, g_mxProjection);
}

Background::~Background()
{
	for (int i = 0; i < STAR_COUNT; i++) {
		delete star[i];
	}
	delete gameover;
}


void Background::UpdateBackground(float delta)
{
	UpdateStars(delta);
	UpdateGameOver(delta);
	UpdateTreasure(delta);
}

void Background::UpdateStars(float delta)
{
	for (int i = 0; i < STAR_COUNT; i++) {
		star[i]->OnUpdate(delta);
		if (star[i]->posY < -20)	star[i]->_isEnd = true;
		if (star[i]->_isEnd == false) {
			star[i]->posY -= delta * BackSpeed;
		}
		else if (star[i]->_isEnd == true) {
			star[i]->posX = rand() % 20 - 10;
			star[i]->posY = rand() % 20 + 10;
			star[i]->_isEnd = false;
		}
	}
}

void Background::UpdateGameOver(float delta)
{
	gameover->OnUpdate(delta);
}

void Background::UpdateTreasure(float delta) {
	if (_isTreasure) {
		treasureTime += delta;
		treasure->OnUpdate(delta);
		treasure->posX = treasurePosX;
		treasure->posY -= delta * treasureSpeed;
		treasure->scaleX = treasure->scaleY = 0.3f;
		if (treasure->posY < -12.0f)	_isTreasure = false;
	}
	else { treasureTime = 0; }
}

void Background::GL_Draw() 
{
	for (int i = 0; i < STAR_COUNT; i++) {
		star[i]->draw();
	}
	if (_isGameover == true)	gameover->draw();
	if (_isTreasure == true && _isTreasureGot == false && treasureTime > 0.1f)	treasure->draw();
}