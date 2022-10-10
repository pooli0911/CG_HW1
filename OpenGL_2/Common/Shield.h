#ifndef SHIELD_H
#define SHIELD_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define SHIELD_NUM 360  // triangles
#define RADIUS 2.5f

class Shield : public GameObject
{
public:
	Shield();
	~Shield() {};

	virtual void OnUpdate(float delta) override;

	void draw();
	void drawW();
};

#endif
