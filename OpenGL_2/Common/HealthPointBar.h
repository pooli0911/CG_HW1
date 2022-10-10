#ifndef HEALTHPOINTBAR_H
#define HEALTHPOINTBAR_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define BAR_NUM 6  // triangles

class HealthPointBar : public GameObject
{
public:
	HealthPointBar();
	~HealthPointBar() {};


	virtual void OnUpdate(float delta) override;


	void draw();
	void drawW();
};
#endif

