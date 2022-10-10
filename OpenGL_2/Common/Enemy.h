#ifndef ENEMY_H
#define ENEMY_H
#include "../Header/Angel.h"
#include "GameObject.h"
#include "EnemyShip.h"
#include "Bullet.h"

#define BULLETS_NUM 50
#define ENEMYBULLETSPEED 20.0f
#define HIT_EFFECT_DELAY 0.05f
#define INIT_POSITION_Y 10.0f
#define ENEMYAPPEARSPEED 18.0f
#define ENEMYBOTTOMPOSITION 8.0f

class Enemy
{
private:
	float _enemyTime;
	float _enemyLongTime;
	float _enemySpeed;
	float _enemyAppearSpeed;
	float _enemyDisplacemetTime;

public:
	Enemy(EnemyShip* enemyship, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor);
	~Enemy();

	int enemyHP;
	bool _isAlive;
	bool _isHit;
	float _enemyHitTime;
	vec4 enemyOriginColor;

	bool _isAppear;

	Bullet* bulletHead;
	Bullet* bulletGet;
	Bullet* bulletTail;
	Bullet* bulletShootHead;
	Bullet* bulletShootGet;

	EnemyShip* enemyship;
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
