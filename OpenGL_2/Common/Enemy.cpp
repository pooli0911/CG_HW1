#include "Enemy.h"

Enemy::Enemy(EnemyShip* enemyship, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor)
{
	this->enemyship = enemyship;
	enemyship = new EnemyShip();

	_isAlive = true;
	_isHit = false;
	_isAppear = true;
	enemyOriginColor = vColor;
	_enemyTime = 0;
	_enemyLongTime = 0;
	_enemySpeed = (rand() % 10 - 5) * 1.0f;
	_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
	_enemyAppearSpeed = ENEMYAPPEARSPEED;
	
	_enemyHitTime = 0;

	_isAttack = true;
	bulletNum = 0;
	CreateBulletList(g_mxModelView, g_mxProjection);
}

Enemy::~Enemy()
{
	delete enemyship;
	DeleteBulletList();
}

void Enemy::UpdateEnemy(float delta)
{
	if (_isHit == true) {
		if (_enemyHitTime < HIT_EFFECT_DELAY)	_enemyHitTime += delta;
		else {
			_isHit = false;
			_enemyHitTime = 0;
			enemyship->setColor(enemyOriginColor);
		}
	}

	_enemyTime += delta;
	_enemyLongTime += delta;
	UpdateShip(delta);
	UpdateBullet(delta);
}

void Enemy::UpdateShip(float delta)
{
	enemyship->OnUpdate(delta);
	if (_isAppear == false) {
		if (enemyship->posX > 10.0f && _enemySpeed > 0) {
			_enemySpeed = (rand() % 10 - 20) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemyTime = 0;
		}
		else if (enemyship->posX < -10.0f && _enemySpeed < 0) {
			_enemySpeed = (rand() % 10 + 5) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemyTime = 0;
		}
		else {
			if (_enemyTime < _enemyDisplacemetTime) {
				enemyship->posX += delta * _enemySpeed;
			}
			else {
				_enemySpeed = (rand() % 10 - 5) * 1.0f;
				_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
				enemyship->posX += delta * _enemySpeed;
				_enemyTime = 0;
			}
		}
	}
	if (_isHit == true) {
		enemyship->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}
	if (enemyship->posY > 8.0f && _isAppear == true) {
		_enemyAppearSpeed -= delta * ( INIT_POSITION_Y - 9.0f ) * ENEMYAPPEARSPEED;
		enemyship->posY -= delta * _enemyAppearSpeed;
	}
	else { 
		enemyship->posY = ENEMYBOTTOMPOSITION + sinf(_enemyLongTime * 2.0f); 
		_isAppear = false;
	}
}

void Enemy::UpdateBullet(float delta)
{
	bulletGet = bulletHead;
	while (bulletGet != nullptr) {
		bulletGet->OnUpdate(delta);
		if (bulletGet->_isShoot == true) {
			bulletGet->posY += delta * bulletGet->BulletSpeed * -1.0f;
		}
		else if (bulletGet->_isShoot == false)	bulletGet->posX = enemyship->posX;
		bulletGet = bulletGet->link;
	}
}

void Enemy::CreateBulletList(mat4 g_mxModelView, mat4 g_mxProjection)
{
	vec4 vColor = vec4(enemyOriginColor);
	bulletHead = new Bullet(enemyship->posX, enemyship->posY);
	bulletHead->BulletSpeed = ENEMYBULLETSPEED;
	bulletHead->setColor(vColor);
	bulletHead->setShader(g_mxModelView, g_mxProjection);
	bulletHead->link = nullptr;
	bulletTail = bulletHead;
	bulletShootHead = bulletHead;
	bulletNum++;

	for (int i = 0; i < BULLETS_NUM - 1; i++) {
		bulletGet = new Bullet(enemyship->posX, enemyship->posY);
		bulletGet->BulletSpeed = ENEMYBULLETSPEED;
		bulletGet->setColor(vColor);
		bulletGet->setShader(g_mxModelView, g_mxProjection);
		bulletGet->link = nullptr;
		bulletTail->link = bulletGet;
		bulletTail = bulletGet;
		bulletNum++;
	}
}

void Enemy::DeleteBulletList()
{
	bulletGet = bulletHead;
	while (bulletHead != nullptr) {
		bulletHead = bulletHead->link;
		delete bulletGet;
		bulletGet = bulletHead;
	}
	bulletNum = 0;
}

void Enemy::Shoot(float delta, float passive_x)
{
	bulletShootGet = bulletShootHead;
	bulletShootGet->_isShoot = true;
	bulletShootGet->posY = enemyship->posY;
	bulletShootGet->posX = passive_x;
}

void Enemy::NextBullet()
{
	bulletNum--;
	bulletShootHead = bulletShootHead->link;

	if (bulletNum == 0) {
		bulletShootHead = bulletHead;
		bulletShootGet = bulletShootHead;
		while (bulletShootGet != nullptr) {
			bulletShootGet = bulletShootGet->link;
			bulletNum++;
		}
	}
}

void Enemy::GL_Draw() {
	if (_enemyLongTime > 0.1f) {
		if (_isAlive)	enemyship->draw();
		bulletGet = bulletHead;
		while (bulletGet != nullptr) {
			if (bulletGet->_isShoot == true)	bulletGet->draw();
			bulletGet = bulletGet->link;
		}
	}
}