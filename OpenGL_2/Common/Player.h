#ifndef PLAYER_H
#define PLAYER_H
#include "../Header/Angel.h"
#include "GameObject.h"
#include "PlayerShip.h"
#include "PlayerShip2.h"
#include "PlayerShip3.h"
#include "PlayerSmallShip.h"
#include "Bullet.h"
#include "Shield.h"
#include "HealthPointBar.h"

#define BULLETS_NUM 50
#define PLAYERBULLETSPEED 30.0f
#define HIT_EFFECT_DELAY 0.05f
#define SMALLSHIPRAD 3.5f
#define SMALLPERIODIC 0.3f

#define HPBAR_NUM 5

class Player
{
private:

public:
	Player(PlayerShip* playership, PlayerShip2* playership2, PlayerShip3* playership3, mat4 g_mxModelView, mat4 g_mxProjection);
	~Player();

	int playerHP;
	int playerFullHP;
	int playerShieldHP;
	bool _isAlive;
	bool _isShield;
	bool _isHit;
	bool _isUpgrade;
	bool _isUpgradeUltimate;

	float _playerHitTime;
	float _playerLongTime;

	HealthPointBar* HPBar[HPBAR_NUM];

	Shield* shield;

	Bullet* bulletHead;
	Bullet* bulletGet;
	Bullet* bulletTail;
	Bullet* bulletShootHead;
	Bullet* bulletShootGet;

	float displacement;
	PlayerShip* playership;
	PlayerShip2* playership2;
	PlayerShip3* playership3;
	PlayerSmallShip* playersmallship;
	mat4 g_mxModelView;
	mat4 g_mxProjection;

	void UpdatePlayer(float delta);
	void UpdateShip(float delta);
	void UpdateShip2(float delta);
	void UpdateShip3(float delta);
	void UpdateSmallShip(float delta);
	void UpdateBullet(float delta);
	void UpdateShield(float delta);
	void UpdateHPBar(float delta);

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