//--------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------功能需求------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------操控與背景部分 ( 8% / 8% )------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//
//(1%)  滑鼠可以控制戰鬥機的左右移動 done
//(1%)  戰鬥機傭有防禦裝置，並以父子關係方式呈現 done
//(1%)  可以發射飛彈 done
//(3%)  能提供連續發射(LINKED LIST，自己撰寫，使用STL 2分) done
//(2%)  能產生有速度感的背景物件，或是其他裝飾性的物件 done
//--------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------敵人部分 ( 11% / 11% )--------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//
//(2%)  有至少三種以上不同外形的敵人(不同的顏色)，基本的四方型不算在內 done
//(3%)  以物件導向的多型來控制所有的敵人
//(1%)  敵人可以不斷的產生，而且具有不同的顏色 done
//(1%)  敵人能隨機朝向玩家發射子彈攻擊 done
//(2%)  戰鬥機發射的子彈可以打到敵人，而且敵人會消失 done
//(2%)  有 BOSS 級的敵人，且至會根據被攻擊的多寡至少三種不同的狀態(外型改變或攻擊方式)可以切換 done
//--------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------玩家部分 ( 4% / 4% )---------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//
//(2%)  能判斷玩家是否被打中 並做出合理的反應 done
//(2%)  玩家的船艦至少有三種狀態(外型改變)，且有提供玩家的船艦可改變狀態的機制 done
//--------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------其他技術 ( 8% / 8% )---------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//
//(2%)提供階層式動態控制，並以時間為基礎進行動態的展示(如: OpenGL_2 的 Example4 ，以自動產生的軌跡去控制相關的物件運動)
//(2%)發射導向飛彈攻擊移動的 Boss
//(2%)敵人被打到有其他的效果 done
//(2%)戰鬥機被打到時有其他的效果 done
//(2%)背景除了速度感物件外，有其他的效果 done
//--------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------總分： ( 31% / 31% )---------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//


#include "Header/Angel.h"
#include "Common/Player.h"
#include "Common/Enemy.h"
#include "Common/Enemy2.h"
#include "Common/Background.h"
#include "Common/Boss.h"

#define SPACE_KEY 32
#define SCREEN_SIZE 800
#define HALF_SIZE (SCREEN_SIZE/2) 
#define VP_HALFWIDTH  12.0f
#define PLAYER_NEXT_BULLET_DELAY 0.3f
#define ENEMY_NEXT_BULLET_DELAY 0.2f
#define ENEMY2_NEXT_BULLET_DELAY 0.3f
#define ENEMY3_NEXT_BULLET_DELAY 0.3f
#define BOSS_NEXT_BULLET_DELAY 0.2f
#define SHOOTPERIOD 3.0f

#define PLAYERHEALTHPOINT 60
#define PLAYERSHIELDHEALTHPOINT 20
#define ENEMYHEALTHPOINT 5
#define BOSSPATTERN1HP 50
#define BOSSPATTERN2HP 100

#define ENEMYROUND 5
#define ENEMYSTAYNUM 3

float TimeCount = 0;
float playerBulletTimeCount = 0;
float enemyBulletTimeCount = 0;
float enemy2BulletTimeCount = 0;
float enemy3BulletTimeCount = 0;
float bossBulletTimeCount = 0;
float shootTimeCount = 0;
float bossBulletDelay = BOSS_NEXT_BULLET_DELAY;
float playerBulletDelay = PLAYER_NEXT_BULLET_DELAY;

bool _isEnemy1Alive = true;
bool _isEnemy2Alive = true;
bool _isEnemy3Alive = true;
bool _isBossAlive = false;
bool _isBossReady = false;
bool _isBossDead = false;
bool _isShoot = true;
int bossPatternNow = 0;

int enemy1count = ENEMYROUND;
int enemy2count = ENEMYROUND;
int enemy3count = ENEMYROUND;

Player* player;
PlayerShip* playership;
PlayerShip2* playership2;
PlayerShip3* playership3;

Enemy* enemy1;
EnemyShip* enemyship1;

Enemy2* enemy2;
EnemyShip2* enemyship2;

Enemy* enemy3;
EnemyShip* enemyship3;

Boss* boss;
BossShip* bossship;
BossShip2* bossship2;

Background* background;


// For Model View and Projection Matrix
mat4 g_mxModelView(1.0f);
mat4 g_mxIdentity(1.0f);
mat4 g_mxProjection;


void IdleProcess();
void CreatePlayer();
void CreateEnemy();
void CreateEnemy2();
void CreateEnemy3();
void CreateBoss();
void CreateBackground();
void CollisonDetect(float delta);
void DrawScreen();
void UpdateScreen(float delta);


void init(void)
{
	g_mxProjection = Ortho(-VP_HALFWIDTH, VP_HALFWIDTH, -VP_HALFWIDTH, VP_HALFWIDTH, -1.0f, 1.0f);

	CreatePlayer();
	CreateEnemy();
	CreateEnemy2();
	CreateEnemy3();
	CreateBackground();
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


void GL_Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawScreen();

	glutSwapBuffers();
}

void onFrameMove(float delta)
{
	TimeCount += delta;
	playerBulletTimeCount += delta;
	enemyBulletTimeCount += delta;
	enemy2BulletTimeCount += delta;
	enemy3BulletTimeCount += delta;
	if (!_isShoot) {
		if (shootTimeCount < SHOOTPERIOD)
			shootTimeCount += delta;
		if (shootTimeCount >= SHOOTPERIOD) {
			_isShoot = true;
			shootTimeCount = 0;
		}
	}


	if (_isBossAlive) {
		bossBulletTimeCount += delta;
		if (boss->bossPattern == 2)	bossBulletDelay = BOSS_NEXT_BULLET_DELAY * 0.8f;
		if (boss->_isLastPattern)	bossBulletDelay = BOSS_NEXT_BULLET_DELAY * 0.5f;
	}
	if (player->_isUpgrade && !player->_isUpgrade)	playerBulletDelay = PLAYER_NEXT_BULLET_DELAY * 0.8f;
	if (player->_isUpgradeUltimate)	playerBulletDelay = PLAYER_NEXT_BULLET_DELAY * 0.5f;
	if (playerBulletTimeCount > playerBulletDelay && _isShoot) {
		if (!player->_isUpgrade) {
			player->Shoot(delta, player->playership->posX);
			player->NextBullet();
		}
		else if (player->_isUpgrade && !player->_isUpgradeUltimate) {
			player->Shoot(delta, player->playership2->posX - 0.5f);
			player->NextBullet();
			player->Shoot(delta, player->playership2->posX + 0.5f);
			player->NextBullet();
			player->Shoot(delta, player->playersmallship->posX - 0.2f);
			player->NextBullet();
		}
		else if (player->_isUpgradeUltimate) {
			player->Shoot(delta, player->playership3->posX - 0.7f);
			player->NextBullet();
			player->Shoot(delta, player->playership2->posX);
			player->NextBullet();
			player->Shoot(delta, player->playership2->posX + 0.7f);
			player->NextBullet();
			player->Shoot(delta, player->playersmallship->posX - 0.2f);
			player->NextBullet();
		}
		playerBulletTimeCount = 0;
	}
	if (enemyBulletTimeCount > ENEMY_NEXT_BULLET_DELAY && enemy1->_isAppear == false){
		enemy1->Shoot(delta, enemy1->enemyship->posX);
		enemy1->NextBullet();
		enemyBulletTimeCount = 0;
	}
	if (enemy2BulletTimeCount > ENEMY2_NEXT_BULLET_DELAY && enemy2->_isAppear == false) {
		enemy2->Shoot(delta, enemy2->enemyship2->posX);
		enemy2->NextBullet();
		enemy2BulletTimeCount = 0;
	}
	if (enemy3BulletTimeCount > ENEMY3_NEXT_BULLET_DELAY && enemy3->_isAppear == false) {
		enemy3->Shoot(delta, enemy3->enemyship->posX);
		enemy3->NextBullet();
		enemy3BulletTimeCount = 0;
	}
	if (bossBulletTimeCount > bossBulletDelay && boss->_isAppear == false) {
		if (bossPatternNow == 1) {
			boss->Shoot(delta, boss->bossship->posX);
			boss->NextBullet();
		}
		else if (bossPatternNow == 2) {
			if (boss->_isLastPattern == true) {
				boss->Shoot(delta, boss->bossship2->posX - 2.0f);
				boss->NextBullet();
				boss->Shoot(delta, boss->bossship2->posX);
				boss->NextBullet();
				boss->Shoot(delta, boss->bossship2->posX + 2.0f);
				boss->NextBullet();
			}
			else {
				boss->Shoot(delta, boss->bossship2->posX);
				boss->NextBullet();
			}
		}
		bossBulletTimeCount = 0;
	}
	if (player->playerHP <= 0) {
		player->_isAlive = false;
		background->_isGameover = true;
	}
	if (player->playerShieldHP < 0)	player->_isShield = false;
	if (enemy1->enemyHP < 0) {
		enemy1->_isAlive = false;
		_isEnemy1Alive = false;
		enemy1count--;
		if (background->_isTreasure == false && enemy1count >= 0 && !player->_isUpgradeUltimate) {
			background->_isTreasure = true;
			background->_isTreasureGot = false;
			background->treasurePosX = enemy1->enemyship->posX;
			background->treasure->posY = enemy1->enemyship->posY;
		}
	}
	if (enemy2->enemyHP < 0) {
		enemy2->_isAlive = false;
		_isEnemy2Alive = false;
		enemy2count--;
	}
	if (enemy3->enemyHP < 0) {
		enemy3->_isAlive = false;
		_isEnemy3Alive = false;
		enemy3count--;
	}
	if (_isBossAlive == true) {
		if (bossPatternNow == 1 && boss->bossPattern1HP < 0) {
			//boss->_isAlive = false;
			//_isBossAlive = false;
			//_isBossDead = true;
			boss->bossship2->posX = boss->bossship->posX;
			boss->bossship2->posY = boss->bossship->posY;
			bossPatternNow++;
			boss->bossPattern = bossPatternNow;
		}
		if (bossPatternNow == 2 && boss->bossPattern2HP < 0) {
			boss->_isAlive = false;
			_isBossAlive = false;
			_isBossDead = true;
			//boss->bossship2->posX = boss->bossship->posX;
			//boss->bossship2->posY = boss->bossship->posY;
			//bossPatternNow++;
			//boss->bossPattern = bossPatternNow;
		}
	}
	CollisonDetect(delta);
	UpdateScreen(delta);
	GL_Display();
}

void CreatePlayer()
{
	vec4 vColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);

	playership = new PlayerShip;
	playership->setColor(vColor);
	playership->setShader(g_mxModelView, g_mxProjection);

	playership2 = new PlayerShip2;
	playership2->setColor(vec4(0.3f, 0.3f, 1.0f, 1.0f));
	playership2->setShader(g_mxModelView, g_mxProjection);

	playership3 = new PlayerShip3;
	playership3->setColor(vec4(1.0f, 0.3f, 1.0f, 1.0f));
	playership3->setShader(g_mxModelView, g_mxProjection);


	player = new Player(playership, playership2, playership3, g_mxModelView, g_mxProjection);
	player->playerHP = player->playerFullHP = PLAYERHEALTHPOINT;
	player->playerShieldHP = PLAYERSHIELDHEALTHPOINT;
}

void CreateEnemy()
{
	vec4 vColor = vec4((float)rand()/((RAND_MAX+1.0f)*2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, 1.0f);
	enemyship1 = new EnemyShip;
	enemyship1->posY = 15.0f;
	enemyship1->setColor(vColor);
	enemyship1->setShader(g_mxModelView, g_mxProjection);
	enemy1 = new Enemy(enemyship1, g_mxModelView, g_mxProjection, vColor);
	enemy1->enemyHP = ENEMYHEALTHPOINT;
	enemy1->enemyOriginColor = vColor;
	_isEnemy1Alive = true;

}

void CreateEnemy2()
{
	vec4 vColor2 = vec4((float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, 1.0f);
	enemyship2 = new EnemyShip2;
	enemyship2->setColor(vColor2);
	enemyship2->setShader(g_mxModelView, g_mxProjection);
	enemy2 = new Enemy2(enemyship2, g_mxModelView, g_mxProjection, vColor2);
	enemy2->enemyHP = ENEMYHEALTHPOINT;
	enemy2->enemy2OriginColor = vColor2;
	_isEnemy2Alive = true;
}

void CreateEnemy3()
{
	vec4 vColor3 = vec4((float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, 1.0f);
	enemyship3 = new EnemyShip;
	enemyship3->setColor(vColor3);
	enemyship3->setShader(g_mxModelView, g_mxProjection);
	enemy3 = new Enemy(enemyship3, g_mxModelView, g_mxProjection, vColor3);
	enemy3->enemyHP = ENEMYHEALTHPOINT;
	enemy3->enemyOriginColor = vColor3;
	_isEnemy3Alive = true;
}

void CreateBoss() {
	bossPatternNow++;
	vec4 vColor = vec4((float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, (float)rand() / ((RAND_MAX + 1.0f) * 2.0f) + 0.5f, 1.0f);
	bossship = new BossShip;
	bossship->setColor(vColor);
	bossship->setShader(g_mxModelView, g_mxProjection);
	bossship2 = new BossShip2;
	bossship2->setColor(vColor);
	bossship2->setShader(g_mxModelView, g_mxProjection);
	boss = new Boss(bossship, bossship2, g_mxModelView, g_mxProjection, vColor);
	boss->bossPattern1HP = boss->bossPattern1FullHP = BOSSPATTERN1HP;
	boss->bossPattern2HP = boss->bossPattern2FullHP = BOSSPATTERN2HP;
	boss->enemyOriginColor = vColor;
	boss->bossPattern = bossPatternNow;
	_isBossAlive = true;
}

void CreateBackground()
{
	background = new Background(g_mxModelView, g_mxProjection);
}


void CollisonDetect(float delta)
{
	player->bulletGet = player->bulletHead;
	while (player->bulletGet != nullptr) {
		if (enemy1->_isAlive) {
			if (player->bulletGet->posX - 2.0f < enemy1->enemyship->posX + 0.5f && player->bulletGet->posX + 2.0f > enemy1->enemyship->posX - 0.5f && player->bulletGet->posY - 1.0f < enemy1->enemyship->posY + 0.5f && player->bulletGet->posY + 1.0f > enemy1->enemyship->posY - 0.5f) {
				player->bulletGet->_isCollide = true;
				player->bulletGet->_isShoot = false;
				player->bulletGet->posX = player->playership->posX;
				player->bulletGet->posY = player->playership->posY + 1.5f;
				enemy1->enemyHP--;
				enemy1->_isHit = true;
			}
		}
		if (enemy2->_isAlive) {
			if (player->bulletGet->posX - 1.0f < enemy2->enemyship2->posX + 0.5f && player->bulletGet->posX + 1.0f > enemy2->enemyship2->posX - 0.5f && player->bulletGet->posY - 1.0f < enemy2->enemyship2->posY + 0.5f && player->bulletGet->posY + 1.0f > enemy2->enemyship2->posY - 0.5f) {
				player->bulletGet->_isCollide = true;
				player->bulletGet->_isShoot = false;
				player->bulletGet->posX = player->playership->posX;
				player->bulletGet->posY = player->playership->posY + 1.5f;
				enemy2->enemyHP--;
				enemy2->_isHit = true;
			}
		}
		if (enemy3->_isAlive) {
			if (player->bulletGet->posX - 2.0f < enemy3->enemyship->posX + 0.5f && player->bulletGet->posX + 2.0f > enemy3->enemyship->posX - 0.5f && player->bulletGet->posY - 1.0f < enemy3->enemyship->posY + 0.5f && player->bulletGet->posY + 1.0f > enemy3->enemyship->posY - 0.5f) {
				player->bulletGet->_isCollide = true;
				player->bulletGet->_isShoot = false;
				player->bulletGet->posX = player->playership->posX;
				player->bulletGet->posY = player->playership->posY + 1.5f;
				enemy3->enemyHP--;
				enemy3->_isHit = true;
			}
		}
		if (_isBossAlive == true) {
			if (boss->_isAlive && bossPatternNow == 1) {
				if (player->bulletGet->posX - 2.0f < boss->bossship->posX + 0.5f && player->bulletGet->posX + 2.0f > boss->bossship->posX - 0.5f && player->bulletGet->posY - 1.0f < boss->bossship->posY + 0.5f && player->bulletGet->posY + 1.0f > boss->bossship->posY - 0.5f) {
					player->bulletGet->_isCollide = true;
					player->bulletGet->_isShoot = false;
					player->bulletGet->posX = player->playership->posX;
					player->bulletGet->posY = player->playership->posY + 1.5f;
					boss->bossPattern1HP--;
					boss->_isHit = true;
				}
			}
			else if (boss->_isAlive && bossPatternNow == 2) {
				if (player->bulletGet->posX - 5.0f < boss->bossship2->posX  && player->bulletGet->posX + 5.0f > boss->bossship2->posX && player->bulletGet->posY - 1.0f < boss->bossship2->posY + 0.5f && player->bulletGet->posY + 1.0f > boss->bossship2->posY - 0.5f) {
					player->bulletGet->_isCollide = true;
					player->bulletGet->_isShoot = false;
					player->bulletGet->posX = player->playership->posX;
					player->bulletGet->posY = player->playership->posY + 1.5f;
					boss->bossPattern2HP--;
					boss->_isHit = true;
				}
			}
		}
		player->bulletGet = player->bulletGet->link;
	}

	if (player->playerHP >= 0) {
		
		enemy1->bulletGet = enemy1->bulletHead;
		while (enemy1->bulletGet != nullptr) {
			if (player->_isShield == true) {
				float shieldDistance = (enemy1->bulletGet->posX - player->playership->posX) * (enemy1->bulletGet->posX - player->playership->posX) + (enemy1->bulletGet->posY - player->playership->posY) * (enemy1->bulletGet->posY - player->playership->posY);
				if (shieldDistance < RADIUS * RADIUS) {
					enemy1->bulletGet->_isCollide = true;
					enemy1->bulletGet->_isShoot = false;
					enemy1->bulletGet->posX = enemy1->enemyship->posX;
					enemy1->bulletGet->posY = enemy1->enemyship->posY;
					player->playerShieldHP--;
				}
			}
			else {
				if (enemy1->bulletGet->posX - 1.0f < player->playership->posX + 0.5f && enemy1->bulletGet->posX + 1.0f > player->playership->posX - 0.5f && enemy1->bulletGet->posY - 1.0f < player->playership->posY + 0.5f && enemy1->bulletGet->posY + 1.0f > player->playership->posY - 0.5f) {
					enemy1->bulletGet->_isCollide = true;
					enemy1->bulletGet->_isShoot = false;
					enemy1->bulletGet->posX = enemy1->enemyship->posX;
					enemy1->bulletGet->posY = enemy1->enemyship->posY;
					player->playerHP--;
					player->_isHit = true;
				}
			}
			enemy1->bulletGet = enemy1->bulletGet->link;
		}

		enemy2->bulletGet = enemy2->bulletHead;
		while (enemy2->bulletGet != nullptr) {
			if (player->_isShield == true) {
				float shieldDistance = (enemy2->bulletGet->posX - player->playership->posX)*(enemy2->bulletGet->posX - player->playership->posX) + (enemy2->bulletGet->posY - player->playership->posY) * (enemy2->bulletGet->posY - player->playership->posY);
				if (shieldDistance < RADIUS * RADIUS) {
					enemy2->bulletGet->_isCollide = true;
					enemy2->bulletGet->_isShoot = false;
					enemy2->bulletGet->posX = enemy2->enemyship2->posX;
					enemy2->bulletGet->posY = enemy2->enemyship2->posY;
					player->playerShieldHP--;
				}
			}
			else {
				if (enemy2->bulletGet->posX - 1.0f < player->playership->posX + 0.5f && enemy2->bulletGet->posX + 1.0f > player->playership->posX - 0.5f && enemy2->bulletGet->posY - 1.0f < player->playership->posY + 0.5f && enemy2->bulletGet->posY + 1.0f > player->playership->posY - 0.5f) {
					enemy2->bulletGet->_isCollide = true;
					enemy2->bulletGet->_isShoot = false;
					enemy2->bulletGet->posX = enemy2->enemyship2->posX;
					enemy2->bulletGet->posY = enemy2->enemyship2->posY;
					player->playerHP--;
					player->_isHit = true;
				}
			}
			enemy2->bulletGet = enemy2->bulletGet->link;
		}

		enemy3->bulletGet = enemy3->bulletHead;
		while (enemy3->bulletGet != nullptr) {
			if (player->_isShield == true) {
				float shieldDistance = (enemy3->bulletGet->posX - player->playership->posX) * (enemy3->bulletGet->posX - player->playership->posX) + (enemy3->bulletGet->posY - player->playership->posY) * (enemy3->bulletGet->posY - player->playership->posY);
				if (shieldDistance < RADIUS * RADIUS) {
					enemy3->bulletGet->_isCollide = true;
					enemy3->bulletGet->_isShoot = false;
					enemy3->bulletGet->posX = enemy3->enemyship->posX;
					enemy3->bulletGet->posY = enemy3->enemyship->posY;
					player->playerShieldHP--;
				}
			}
			else {
				if (enemy3->bulletGet->posX - 1.0f < player->playership->posX + 0.5f && enemy3->bulletGet->posX + 1.0f > player->playership->posX - 0.5f && enemy3->bulletGet->posY - 1.0f < player->playership->posY + 0.5f && enemy3->bulletGet->posY + 1.0f > player->playership->posY - 0.5f) {
					enemy3->bulletGet->_isCollide = true;
					enemy3->bulletGet->_isShoot = false;
					enemy3->bulletGet->posX = enemy3->enemyship->posX;
					enemy3->bulletGet->posY = enemy3->enemyship->posY;
					player->playerHP--;
					player->_isHit = true;
				}
			}
			enemy3->bulletGet = enemy3->bulletGet->link;
		}

		if (_isBossAlive == true) {
			boss->bulletGet = boss->bulletHead;
			while (boss->bulletGet != nullptr) {
				if (player->_isShield == true) {
					float shieldDistance = (boss->bulletGet->posX - player->playership->posX) * (boss->bulletGet->posX - player->playership->posX) + (boss->bulletGet->posY - player->playership->posY) * (boss->bulletGet->posY - player->playership->posY);
					if (shieldDistance < RADIUS * RADIUS) {
						boss->bulletGet->_isCollide = true;
						boss->bulletGet->_isShoot = false;
						boss->bulletGet->posX = boss->bossship->posX;
						boss->bulletGet->posY = boss->bossship->posY;
						player->playerShieldHP--;
					}
				}
				else {
					if (boss->bulletGet->posX - 1.0f < player->playership->posX + 0.5f && boss->bulletGet->posX + 1.0f > player->playership->posX - 0.5f && boss->bulletGet->posY - 1.0f < player->playership->posY + 0.5f && boss->bulletGet->posY + 1.0f > player->playership->posY - 0.5f) {
						boss->bulletGet->_isCollide = true;
						boss->bulletGet->_isShoot = false;
						boss->bulletGet->posX = boss->bossship->posX;
						boss->bulletGet->posY = boss->bossship->posY;
						player->playerHP--;
						player->_isHit = true;
					}
				}
				boss->bulletGet = boss->bulletGet->link;
			}
		}

		if (background->_isTreasure) {
			if (player->_isShield == true) {
				float shieldDistance = (background->treasure->posX - player->playership->posX) * (background->treasure->posX - player->playership->posX) + (background->treasure->posY - player->playership->posY) * (background->treasure->posY - player->playership->posY);
				if (shieldDistance < RADIUS * RADIUS) {
					background->_isTreasure = false;
					background->_isTreasureGot = true;
					if (!player->_isUpgrade)	player->_isUpgrade = true;
					else if (!player->_isUpgradeUltimate)	player->_isUpgradeUltimate = true;
				}
			}
			else {
				if (background->treasure->posX - 1.0f < player->playership->posX + 0.5f && background->treasure->posX + 1.0f > player->playership->posX - 0.5f && background->treasure->posY - 1.0f < player->playership->posY + 0.5f && background->treasure->posY + 1.0f > player->playership->posY - 0.5f) {
					background->_isTreasure = false;
					background->_isTreasureGot = true;
					if (!player->_isUpgrade)	player->_isUpgrade = true;
					else if (!player->_isUpgradeUltimate)	player->_isUpgradeUltimate = true;
				}
			}
		}
	}
}

void DrawScreen()
{
	background->GL_Draw();
	if (player->_isAlive == true) {
		player->GL_Draw();
		if (enemy1->_isAlive == true)	enemy1->GL_Draw();
		if (enemy2->_isAlive == true)	enemy2->GL_Draw();
		if (enemy3->_isAlive == true)	enemy3->GL_Draw();
		if (_isBossAlive == true && _isBossReady == true)	boss->GL_Draw();
	}
}

void UpdateScreen(float delta)
{
	if (player->_isAlive == true) {
		player->UpdatePlayer(delta);
		if (enemy1->_isAlive == true)	enemy1->UpdateEnemy(delta);
		else if (enemy1count > 0){
			enemy1->UpdateEnemy(delta);
			CreateEnemy();
		}
		if (enemy2->_isAlive == true)	enemy2->UpdateEnemy(delta);
		else if (enemy2count > 0) {
			enemy2->UpdateEnemy(delta);
			CreateEnemy2();
		}
		if (enemy3->_isAlive == true)	enemy3->UpdateEnemy(delta);
		else if (enemy3count > 0) {
			enemy3->UpdateEnemy(delta);
			CreateEnemy3();
		}
		if (_isEnemy1Alive == false && _isEnemy2Alive == false && _isEnemy3Alive == false) {
			_isBossReady = true;
		}
		if (_isBossReady == true && _isBossAlive == false && _isBossDead == false) {
			CreateBoss();
			_isBossReady = false;
		}
		if (_isBossAlive == true)	boss->UpdateEnemy(delta);
	}
	background->UpdateBackground(delta);
}


void Win_Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case  SPACE_KEY:

		break;

	case 033:
		//glutIdleFunc(NULL);
		//delete player;
		//delete playership;
		//exit(EXIT_SUCCESS);
		break;
	}
}
//----------------------------------------------------------------------------
void Win_Mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) _isShoot = false;
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN);
		break;
	default:
		_isShoot = true;
		break;
	}
}


void Win_MouseMotion(int x, int y) {
	player->displacement = (float)(x - HALF_SIZE) / (float)(HALF_SIZE) * 15.0f;
}

void Win_SpecialKeyboard(int key, int x, int y) {
	mat4 rx, ry, rz;
	switch (key) {
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------------
void GL_Reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
}

//----------------------------------------------------------------------------

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_SIZE, SCREEN_SIZE);
	glutInitContextVersion(3, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Shooting Game");

	glewExperimental = GL_TRUE;
	glewInit();

	init();

	glutMouseFunc(Win_Mouse);
	glutMotionFunc(Win_MouseMotion);
	glutPassiveMotionFunc(Win_MouseMotion);
	glutKeyboardFunc(Win_Keyboard);
	glutSpecialFunc(Win_SpecialKeyboard);
	glutDisplayFunc(GL_Display);
	glutReshapeFunc(GL_Reshape);
	glutIdleFunc(IdleProcess);

	glutMainLoop();
	return 0;
}