#pragma once

#include <iostream>
#include "raylib.h"
#include "GameObject.h"


class Paddle : public GameObject {

public:
	Paddle(Vector2, bool, const char*);
	virtual ~Paddle();
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	virtual void onScore();
	void doPlayerInputs();
	void doCpuInputs();
	void CPUFindBall();
	Vector2 mVisibleWH;
	bool mIsPlayer;
	Ball* mCurBall;
	Vector2 mStartPos;
};