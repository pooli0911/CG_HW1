#ifndef BOSS_H
#define BOSS_H
#include "../Header/Angel.h"
#include "GameObject.h"
#include "BossShip.h"
#include "Bullet.h"
#include "HealthPointBar.h"
#include "Bossship2.h"

#define BULLETS_NUM 50
#define ENEMYBULLETSPEED 20.0f
#define HIT_EFFECT_DELAY 0.05f
#define INIT_POSITION_Y 10.0f
#define ENEMYAPPEARSPEED 18.0f
#define ENEMYBOTTOMPOSITION 8.0f

class Boss
{
private:
	float _enemyTime;
	float _enemyLongTime;
	float _enemySpeed;
	float _enemyAppearSpeed;
	float _enemyDisplacemetTime;

public:
	Boss(BossShip* bossship, BossShip2* bossship2, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor);
	~Boss();

	int bossPattern1HP;
	int bossPattern1FullHP;
	int bossPattern2HP;
	int bossPattern2FullHP;
	bool _isLastPattern;
	bool _isAlive;
	bool _isHit;
	float _enemyHitTime;
	vec4 enemyOriginColor;
	int bossPattern;

	HealthPointBar* bossHPBar;

	bool _isAppear;

	Bullet* bulletHead;
	Bullet* bulletGet;
	Bullet* bulletTail;
	Bullet* bulletShootHead;
	Bullet* bulletShootGet;

	BossShip* bossship;
	BossShip2* bossship2;
	mat4 g_mxModelView;
	mat4 g_mxProjection;

	void UpdateEnemy(float delta);
	void UpdateShip(float delta);
	void UpdateShip2(float delta);
	void UpdateBullet(float delta);
	void UpdateBossHPBar(float delta);

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

