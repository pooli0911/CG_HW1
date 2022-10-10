#ifndef BULLET_H
#define BULLET_H
#include "../header/Angel.h"
#include "GameObject.h"

typedef Angel::vec4  color4;
typedef Angel::vec4  point4;

#define BULLET_NUM 6

class Bullet : public GameObject
{
protected:

public:
	Bullet(float x, float y);
	~Bullet() {};
	Bullet* link;

	bool _isCollide;
	bool _isShoot;
	float BulletSpeed;


	virtual void OnUpdate(float delta) override;

	void ShootUp(float delta, float passive_x);
	void ShootDown(float delta, float passive_x);
	void ResetBullet(float x, float y);
	void draw();
	void drawW();
};
#endif
