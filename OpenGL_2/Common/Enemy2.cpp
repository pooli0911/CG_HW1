#include "Enemy2.h"

Enemy2::Enemy2(EnemyShip2* enemyship2, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor)
{
	this->enemyship2 = enemyship2;
	enemyship2 = new EnemyShip2();

	_isAlive = true;
	_isHit = false;
	_isAppear = true;
	_enemyHitTime = 0;
	enemy2OriginColor = vColor;
	_enemy2Time = 0;
	_enemy2LongTime = 0;
	_enemy2Speed = (rand() % 10 - 5) * 1.0f;
	_enemy2DisplacemetTime = (rand() % 10 + 5) * 0.1f;
	_enemy2AppearSpeed = ENEMYAPPEARSPEED;

	_isAttack = true;
	bulletNum = 0;
	CreateBulletList(g_mxModelView, g_mxProjection);
}

Enemy2::~Enemy2()
{
	delete enemyship2;
	DeleteBulletList();
}

void Enemy2::UpdateEnemy(float delta)
{
	if (_isHit == true) {
		if (_enemyHitTime < HIT_EFFECT_DELAY)	_enemyHitTime += delta;
		else {
			_isHit = false;
			_enemyHitTime = 0;
			enemyship2->setColor(enemy2OriginColor);
		}
	}
	_enemy2Time += delta;
	_enemy2LongTime += delta;
	UpdateShip(delta);
	UpdateBullet(delta);
}

void Enemy2::UpdateShip(float delta)
{
	enemyship2->OnUpdate(delta);
	if (_isAppear == false) {
		if (enemyship2->posX > 10.0f && _enemy2Speed > 0) {
			_enemy2Speed = (rand() % 10 - 20) * 1.0f;
			_enemy2DisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemy2Time = 0;
		}
		else if (enemyship2->posX < -10.0f && _enemy2Speed < 0) {
			_enemy2Speed = (rand() % 10 + 5) * 1.0f;
			_enemy2DisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemy2Time = 0;
		}
		else {
			if (_enemy2Time < _enemy2DisplacemetTime) {
				enemyship2->posX += delta * _enemy2Speed;
			}
			else {
				_enemy2Speed = (rand() % 10 - 5) * 1.0f;
				_enemy2DisplacemetTime = (rand() % 10 + 5) * 0.1f;
				enemyship2->posX += delta * _enemy2Speed;
				_enemy2Time = 0;
			}
		}
	}
	if (_isHit == true) {
		enemyship2->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}
	if (enemyship2->posY > 8.0f && _isAppear == true) {
		_enemy2AppearSpeed -= delta * (INIT_POSITION_Y - 9.0f) * ENEMYAPPEARSPEED;
		enemyship2->posY -= delta * _enemy2AppearSpeed;
	}
	else {
		enemyship2->posY = ENEMYBOTTOMPOSITION + sinf(_enemy2LongTime * 2.0f);
		_isAppear = false;
	}
}

void Enemy2::UpdateBullet(float delta)
{
	bulletGet = bulletHead;
	while (bulletGet != nullptr) {
		bulletGet->OnUpdate(delta);
		if (bulletGet->_isShoot == true) {
			bulletGet->posY += delta * bulletGet->BulletSpeed * -1.0f;
		}
		else if (bulletGet->_isShoot == false)	bulletGet->posX = enemyship2->posX;
		bulletGet = bulletGet->link;
	}
}

void Enemy2::CreateBulletList(mat4 g_mxModelView, mat4 g_mxProjection)
{
	vec4 vColor = enemy2OriginColor;
	bulletHead = new Bullet(enemyship2->posX, enemyship2->posY);
	bulletHead->BulletSpeed = ENEMY2BULLETSPEED;
	bulletHead->setColor(vColor);
	bulletHead->setShader(g_mxModelView, g_mxProjection);
	bulletHead->link = nullptr;
	bulletTail = bulletHead;
	bulletShootHead = bulletHead;
	bulletNum++;

	for (int i = 0; i < BULLETS_NUM - 1; i++) {
		bulletGet = new Bullet(enemyship2->posX, enemyship2->posY);
		bulletGet->BulletSpeed = ENEMY2BULLETSPEED;
		bulletGet->setColor(vColor);
		bulletGet->setShader(g_mxModelView, g_mxProjection);
		bulletGet->link = nullptr;
		bulletTail->link = bulletGet;
		bulletTail = bulletGet;
		bulletNum++;
	}
}

void Enemy2::DeleteBulletList()
{
	bulletGet = bulletHead;
	while (bulletHead != nullptr) {
		bulletHead = bulletHead->link;
		delete bulletGet;
		bulletGet = bulletHead;
	}
	bulletNum = 0;
}

void Enemy2::Shoot(float delta, float passive_x)
{
	bulletShootGet = bulletShootHead;
	bulletShootGet->_isShoot = true;
	bulletShootGet->posY = enemyship2->posY;
	bulletShootGet->posX = passive_x;
}

void Enemy2::NextBullet()
{
	bulletNum--;
	bulletShootHead = bulletShootHead->link;
	//bulletShootGet = bulletShootHead;

	if (bulletNum == 0) {
		bulletShootHead = bulletHead;
		bulletShootGet = bulletShootHead;
		while (bulletShootGet != nullptr) {
			//bulletShootGet->ResetBullet(playership->posX, playership->posY + 1.5f);
			bulletShootGet = bulletShootGet->link;
			bulletNum++;
		}
	}
}

void Enemy2::GL_Draw() {
	if (_enemy2LongTime > 0.1f) {
		if (_isAlive)	enemyship2->draw();
		bulletGet = bulletHead;
		while (bulletGet != nullptr) {
			if (bulletGet->_isShoot == true)	bulletGet->draw();
			bulletGet = bulletGet->link;
		}
	}
}