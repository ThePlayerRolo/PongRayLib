#pragma once

#include <iostream>
#include "raylib.h"
#include "GameObject.h"

class Ball : public GameObject {
public:
	Ball(Vector2);
	virtual ~Ball();
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	virtual void onScore();

	f32 mRadius;
	bool isNextPlayer;
};
