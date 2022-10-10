#ifndef STAR_H
#define STAR_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define STAR_NUM 9

class Star : public GameObject
{
public:
	Star();
	~Star() {};

	virtual void OnUpdate(float delta) override;

	bool _isEnd;

	void draw();
	void drawW();
};

#endif