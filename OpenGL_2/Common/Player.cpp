#include "Player.h"

Player::Player(PlayerShip* playership, PlayerShip2* playership2, PlayerShip3* playership3, mat4 g_mxModelView, mat4 g_mxProjection)
{
	this->playership = playership;
	playership = new PlayerShip();

	vec4 vColor = vec4(1.0f, 1.0f, 1.0f, 0.3f);
	shield = new Shield();
	shield->setColor(vColor);
	shield->setShader(g_mxModelView, g_mxProjection);
	shield->posX = playership->posX;
	shield->posY = playership->posY;

	vColor = vec4(1.0f, 1.0f, 1.0f, 0.3f);
	playersmallship = new PlayerSmallShip();
	playersmallship->setColor(vColor);
	playersmallship->setShader(g_mxModelView, g_mxProjection);
	playersmallship->posX = playership->posX + cosf(_playerLongTime/SMALLPERIODIC) * SMALLSHIPRAD;
	playersmallship->posY = playership->posY + sinf(_playerLongTime/SMALLPERIODIC) * SMALLSHIPRAD;

	this->playership2 = playership2;
	playership2 = new PlayerShip2();

	this->playership3 = playership3;
	playership3 = new PlayerShip3();

	vColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	for (int i = 0; i < HPBAR_NUM; i++)
	{
		HPBar[i] = new HealthPointBar();
		HPBar[i]->setColor(vColor);
		HPBar[i]->setShader(g_mxModelView, g_mxProjection);
		HPBar[i]->posX = playership->posX + 0.3f * i - (HPBAR_NUM - 1) / 2 * 0.3f;
		HPBar[i]->posY = playership->posY - 2.0f;
		HPBar[i]->scaleX = HPBar[i]->scaleY = 0.8f;
	}

	_isAlive = true;
	_isShield = true;
	_isHit = false;
	_isUpgrade = false;
	_isUpgradeUltimate = false;
	_playerHitTime = 0;
	_playerLongTime = 0;

	_isAttack = true;
	bulletNum = 0;
	CreateBulletList(g_mxModelView, g_mxProjection);
}

Player::~Player()
{
	delete playership;
	DeleteBulletList();
	delete shield;
	delete HPBar;
}

void Player::UpdatePlayer(float delta)
{
	_playerLongTime += delta;
	if (_isHit == true) {
		if (_playerHitTime < HIT_EFFECT_DELAY)	_playerHitTime += delta;
		else {
			_isHit = false;
			_playerHitTime = 0;
			if (!_isUpgrade) {
				playership->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
			}
			if (_isUpgrade && !_isUpgradeUltimate) {
				playership2->setColor(vec4(0.3f, 0.3f, 1.0f, 1.0f));
				playersmallship->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
			}
			if (_isUpgradeUltimate) {
				playership3->setColor(vec4(1.0f, 0.3f, 1.0f, 1.0f));
				playersmallship->setColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
			}
		}
	}
	UpdateShip(delta);
	UpdateShip2(delta);
	UpdateShip3(delta);
	UpdateSmallShip(delta);
	UpdateBullet(delta);
	UpdateShield(delta);
	UpdateHPBar(delta);
}

void Player::UpdateShip(float delta)
{
	playership->OnUpdate(delta);
	playership->posX = displacement;
	playership->posY = -8.0f;
	if (_isHit == true) {
		playership->setColor(vec4(0.5f, 0.5f, 0.5f, 1.0f));
	}
}

void Player::UpdateShip2(float delta)
{
	playership2->OnUpdate(delta);
	playership2->posX = displacement;
	playership2->posY = -8.0f;
	if (_isHit == true) {
		playership2->setColor(vec4(0.5f, 0.5f, 0.5f, 1.0f));
	}
}

void Player::UpdateShip3(float delta)
{
	playership3->OnUpdate(delta);
	playership3->posX = displacement;
	playership3->posY = -8.0f;
	playership3->scaleX = playership3->scaleY = 0.8f;
	if (_isHit == true) {
		playership3->setColor(vec4(0.5f, 0.5f, 0.5f, 1.0f));
	}
}

void Player::UpdateSmallShip(float delta)
{
	playersmallship->OnUpdate(delta);
	playersmallship->posX = displacement + cosf(_playerLongTime/SMALLPERIODIC) * SMALLSHIPRAD;
	playersmallship->posY = -8.0f + sinf(_playerLongTime/ SMALLPERIODIC) * SMALLSHIPRAD;
	playersmallship->scaleX = playersmallship->scaleY = 0.5f;
	if (_isHit == true) {
		playersmallship->setColor(vec4(0.5f, 0.5f, 0.5f, 1.0f));
	}
}

void Player::UpdateBullet(float delta)
{
	bulletGet = bulletHead;
	while (bulletGet != nullptr) {
		bulletGet->OnUpdate(delta);
		if (bulletGet->_isShoot == true)	bulletGet->posY += delta * bulletGet->BulletSpeed;
		else if (bulletGet->_isShoot == false)	bulletGet->posX = playership->posX;
		bulletGet = bulletGet->link;
	}
}

void Player::UpdateShield(float delta)
{
	shield->OnUpdate(delta);
	shield->posX = playership->posX;
	shield->posY = playership->posY;
	if (_isUpgradeUltimate)	shield->scaleX = shield->scaleY = 1.2f;
}

void Player::UpdateHPBar(float delta)
{
	for (int i = 0; i < HPBAR_NUM; i++)
	{
		HPBar[i]->OnUpdate(delta);
		HPBar[i]->posX = playership->posX + 0.3f * i - (HPBAR_NUM - 1) / 2 * 0.3f;
		HPBar[i]->posY = playership->posY - 2.0f;
		HPBar[i]->scaleX = HPBar[i]->scaleY = 0.8f;
	}
}

void Player::CreateBulletList(mat4 g_mxModelView, mat4 g_mxProjection)
{
	vec4 vColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	bulletHead = new Bullet(playership->posX, playership->posY + 1.5f);
	bulletHead->BulletSpeed = PLAYERBULLETSPEED;
	bulletHead->setColor(vColor);
	bulletHead->setShader(g_mxModelView, g_mxProjection);
	bulletHead->link = nullptr;
	bulletTail = bulletHead;
	bulletShootHead = bulletHead;
	bulletNum++;

	for (int i = 0; i < BULLETS_NUM - 1; i++) {
		bulletGet = new Bullet(playership->posX, playership->posY + 1.5f);
		bulletGet->BulletSpeed = PLAYERBULLETSPEED;
		bulletGet->setColor(vColor);
		bulletGet->setShader(g_mxModelView, g_mxProjection);
		bulletGet->link = nullptr;
		bulletTail->link = bulletGet;
		bulletTail = bulletGet;
		bulletNum++;
	}
}

void Player::DeleteBulletList()
{
	bulletGet = bulletHead;
	while (bulletHead != nullptr) {
		bulletHead = bulletHead->link;
		delete bulletGet;
		bulletGet = bulletHead;
	}
	bulletNum = 0;
}

void Player::Shoot(float delta, float passive_x)
{
	bulletShootGet = bulletShootHead;
	bulletShootGet->_isShoot = true;
	bulletShootGet->posY = playership->posY + 1.5f;
	bulletShootGet->posX = passive_x;
}

void Player::NextBullet()
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

void Player::GL_Draw() {
	if (_isUpgrade == false)	playership->draw();
	else if (!_isUpgradeUltimate) {
		playership2->draw();
		playersmallship->draw();
	}
	else if (_isUpgradeUltimate) {
		playership3->draw();
		playersmallship->draw();
	}
	if (_isShield == true)	shield->draw();
	bulletGet = bulletHead;
	while (bulletGet != nullptr) {
		if (bulletGet->_isShoot == true)	bulletGet->draw();
		bulletGet = bulletGet->link;
	}
	
	for (int i = 0; i < playerHP * HPBAR_NUM / playerFullHP; i++)
	{
		HPBar[i]->draw();
	}
}