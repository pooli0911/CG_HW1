#ifndef ENEMY2_H
#define ENEMY2_H
#include "../Header/Angel.h"
#include "GameObject.h"
#include "EnemyShip2.h"
#include "Bullet.h"

#define BULLETS_NUM 50
#define ENEMY2BULLETSPEED 20.0f
#define HIT_EFFECT_DELAY 0.05f
#define INIT_POSITION_Y 10.0f
#define ENEMYAPPEARSPEED 18.0f
#define ENEMYBOTTOMPOSITION 8.0f

class Enemy2
{
private:
	float _enemy2Time;
	float _enemy2LongTime;
	float _enemy2Speed;
	float _enemy2AppearSpeed;
	float _enemy2DisplacemetTime;

public:
	Enemy2(EnemyShip2* enemyship2, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor);
	~Enemy2();

	int enemyHP;
	bool _isAlive;
	bool _isHit;

	bool _isAppear;
	vec4 enemy2OriginColor;

	float _enemyHitTime;

	Bullet* bulletHead;
	Bullet* bulletGet;
	Bullet* bulletTail;
	Bullet* bulletShootHead;
	Bullet* bulletShootGet;

	EnemyShip2* enemyship2;
	mat4 g_mxModelView;
	mat4 g_mxProjection;

	void UpdateEnemy(float delta);
	void UpdateShip(float delta);
	void UpdateBullet(float delta);

	// for bullet
	bool _isAttack;
	int bulletNum;

	void CreateBulletList(mat4 g_mxModelView, mat4 g_mxProjection);
	void DeleteBulletList();
	void Shoot(float delta, float passive_x);
	void NextBullet();

	void GL_Draw();

};
#endif