#ifndef TREASURE_H
#define TREASURE_H
#include "../Header/Angel.h"
#include "GameObject.h"

#define TREASURE_NUM 24  // triangles

class Treasure : public GameObject
{
public:
	Treasure();
	~Treasure() {};


	virtual void OnUpdate(float delta) override;


	void draw();
	void drawW();
};
#endif
