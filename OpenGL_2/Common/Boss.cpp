#include "Boss.h"

Boss::Boss(BossShip* bossship, BossShip2* bossship2, mat4 g_mxModelView, mat4 g_mxProjection, vec4 vColor)
{
	this->bossship = bossship;
	bossship = new BossShip();

	this->bossship2 = bossship2;
	bossship2 = new BossShip2();

	_isAlive = true;
	_isHit = false;
	_isAppear = true;
	_isLastPattern = false;
	enemyOriginColor = vColor;

	bossPattern = 1;
	_enemyTime = 0;
	_enemyLongTime = 0;
	_enemySpeed = (rand() % 10 - 5) * 1.0f;
	_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
	_enemyAppearSpeed = ENEMYAPPEARSPEED;

	_enemyHitTime = 0;

	bossHPBar = new HealthPointBar();
	bossHPBar->setColor(vec4(1.0f,1.0f,1.0f,1.0f));
	bossHPBar->setShader(g_mxModelView, g_mxProjection);
	bossHPBar->posX = 0.0f;
	bossHPBar->posY = 11.5f;
	bossHPBar->scaleX = 100.0f;
	bossHPBar->scaleY = 0.8f;
	
	_isAttack = true;
	bulletNum = 0;
	CreateBulletList(g_mxModelView, g_mxProjection);
}

Boss::~Boss()
{
	delete bossship;
	delete bossship2;
	DeleteBulletList();
	delete bossHPBar;
}

void Boss::UpdateEnemy(float delta)
{
	if (_isHit == true) {
		if (_enemyHitTime < HIT_EFFECT_DELAY)	_enemyHitTime += delta;
		else {
			_isHit = false;
			_enemyHitTime = 0;
			bossship->setColor(enemyOriginColor);
			bossHPBar->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}


	_enemyTime += delta;
	_enemyLongTime += delta;
	if (bossPattern == 1)	UpdateShip(delta);
	else if (bossPattern == 2) {
		if ((float)bossPattern2HP / (float)bossPattern2FullHP < 0.5f)	_isLastPattern = true;
		UpdateShip2(delta);
	}
	UpdateBullet(delta);
	UpdateBossHPBar(delta);
}

void Boss::UpdateShip(float delta)
{
	bossship->OnUpdate(delta);
	if (_isAppear == false) {
		if (bossship->posX > 10.0f && _enemySpeed > 0) {
			_enemySpeed = (rand() % 10 - 20) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemyTime = 0;
		}
		else if (bossship->posX < -10.0f && _enemySpeed < 0) {
			_enemySpeed = (rand() % 10 + 5) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
			_enemyTime = 0;
		}
		else {
			if (_enemyTime < _enemyDisplacemetTime) {
				bossship->posX += delta * _enemySpeed;
			}
			else {
				_enemySpeed = (rand() % 10 - 5) * 1.0f;
				_enemyDisplacemetTime = (rand() % 10 + 5) * 0.1f;
				bossship->posX += delta * _enemySpeed;
				_enemyTime = 0;
			}
		}
	}
	if (_isHit == true) {
		bossship->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}
	if (bossship->posY > 8.0f && _isAppear == true) {
		_enemyAppearSpeed -= delta * (INIT_POSITION_Y - 9.0f) * ENEMYAPPEARSPEED;
		bossship->posY -= delta * _enemyAppearSpeed;
	}
	else {
		bossship->posY = ENEMYBOTTOMPOSITION + sinf(_enemyLongTime * 2.0f);
		_isAppear = false;
	}
}

void Boss::UpdateShip2(float delta)
{
	bossship2->OnUpdate(delta);
	bossship2->scaleX = bossship->scaleY = 0.8f;
	if (_isAppear == false) {
		if (bossship2->posX > 10.0f && _enemySpeed > 0) {
			_enemySpeed = (rand() % 5 - 20) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 3) * 0.1f;
			_enemyTime = 0;
		}
		else if (bossship2->posX < -10.0f && _enemySpeed < 0) {
			_enemySpeed = (rand() % 5 + 10) * 1.0f;
			_enemyDisplacemetTime = (rand() % 10 + 3) * 0.1f;
			_enemyTime = 0;
		}
		else {
			if (_enemyTime < _enemyDisplacemetTime) {
				bossship2->posX += delta * _enemySpeed * 1.0f;
			}
			else {
				_enemySpeed = (rand() % 10 - 5) * 1.5f;
				_enemyDisplacemetTime = (rand() % 10 + 3) * 0.1f;
				bossship2->posX += delta * _enemySpeed * 1.0f;
				_enemyTime = 0;
			}
		}
	}
	if (_isHit == true) {
		bossship2->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}
	if (bossship2->posY > 8.0f && _isAppear == true) {
		_enemyAppearSpeed -= delta * (INIT_POSITION_Y - 9.0f) * ENEMYAPPEARSPEED;
		bossship2->posY -= delta * _enemyAppearSpeed;
	}
	else {
		bossship2->posY = ENEMYBOTTOMPOSITION + sinf(_enemyLongTime * 2.0f);
		_isAppear = false;
	}
}

void Boss::UpdateBullet(float delta)
{
	bulletGet = bulletHead;
	while (bulletGet != nullptr) {
		bulletGet->OnUpdate(delta);
		if (bulletGet->_isShoot == true) {
			bulletGet->posY += delta * bulletGet->BulletSpeed * -1.0f;
		}
		else if (bulletGet->_isShoot == false) {
			if (bossPattern == 1)	bulletGet->posX = bossship->posX;
			else if (bossPattern == 2)	bulletGet->posX = bossship2->posX;
		}
		bulletGet = bulletGet->link;
	}
}

void Boss::UpdateBossHPBar(float delta) 
{
	bossHPBar->OnUpdate(delta);
	if (bossPattern == 1) {
		bossHPBar->posX = 0.0f - (1.0f - ((float)bossPattern1HP / (float)bossPattern1FullHP)) * 10.0f;
		bossHPBar->posY = 11.5f;
		bossHPBar->scaleX = ((float)bossPattern1HP / (float)bossPattern1FullHP) * 100.0f;
		bossHPBar->scaleY = 0.8f;
		bossHPBar->setColor(vec4(1.0f, ((float)bossPattern1HP / (float)bossPattern1FullHP), ((float)bossPattern1HP / (float)bossPattern1FullHP), 1.0f));
	}
	else if (bossPattern == 2) {
		bossHPBar->posX = 0.0f - (1.0f - ((float)bossPattern2HP / (float)bossPattern2FullHP)) * 10.0f;
		bossHPBar->posY = 11.5f;
		bossHPBar->scaleX = ((float)bossPattern2HP / (float)bossPattern2FullHP) * 100.0f;
		bossHPBar->scaleY = 0.8f;
		bossHPBar->setColor(vec4(1.0f, ((float)bossPattern2HP / (float)bossPattern2FullHP), ((float)bossPattern2HP / (float)bossPattern2FullHP), 1.0f));
	}
	if (_isHit == true) {
		bossHPBar->setColor(vec4(0.0f, 0.0f, 0.0f, 0.0f));
	}
}

void Boss::CreateBulletList(mat4 g_mxModelView, mat4 g_mxProjection)
{
	if (bossPattern == 1)	bulletHead = new Bullet(bossship->posX, bossship->posY);
	else if (bossPattern == 2)	bulletHead = new Bullet(bossship2->posX, bossship2->posY);
	bulletHead->BulletSpeed = ENEMYBULLETSPEED;
	bulletHead->setColor(enemyOriginColor);
	bulletHead->setShader(g_mxModelView, g_mxProjection);
	bulletHead->link = nullptr;
	bulletTail = bulletHead;
	bulletShootHead = bulletHead;
	bulletNum++;

	for (int i = 0; i < BULLETS_NUM - 1; i++) {
		if (bossPattern == 1)	bulletGet = new Bullet(bossship->posX, bossship->posY);
		else if (bossPattern == 2)	bulletGet = new Bullet(bossship2->posX, bossship2->posY);
		bulletGet->BulletSpeed = ENEMYBULLETSPEED;
		bulletGet->setColor(enemyOriginColor);
		bulletGet->setShader(g_mxModelView, g_mxProjection);
		bulletGet->link = nullptr;
		bulletTail->link = bulletGet;
		bulletTail = bulletGet;
		bulletNum++;
	}
}

void Boss::DeleteBulletList()
{
	bulletGet = bulletHead;
	while (bulletHead != nullptr) {
		bulletHead = bulletHead->link;
		delete bulletGet;
		bulletGet = bulletHead;
	}
	bulletNum = 0;
}

void Boss::Shoot(float delta, float passive_x)
{
	bulletShootGet = bulletShootHead;
	bulletShootGet->_isShoot = true;
	if (bossPattern == 1)	bulletShootGet->posY = bossship->posY;
	else if (bossPattern == 2)	bulletShootGet->posY = bossship2->posY;
	bulletShootGet->posX = passive_x;
}

void Boss::NextBullet()
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

void Boss::GL_Draw() {
	if (_enemyLongTime > 0.1f) {
		if (_isAlive) {
			if (bossPattern == 1)	bossship->draw();
			else if (bossPattern == 2) bossship2->draw();
			bossHPBar->draw();
		}
		bulletGet = bulletHead;
		while (bulletGet != nullptr) {
			if (bulletGet->_isShoot == true)	bulletGet->draw();
			bulletGet = bulletGet->link;
		}
	}
}