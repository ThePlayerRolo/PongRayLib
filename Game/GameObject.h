#pragma once

#include <iostream>
#include "raylib.h"
#include "../types.h"

class GameObject {
public:
	GameObject(Vector2, Rectangle, const char*);
	virtual ~GameObject();
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	virtual void onScore();
	bool isCollidedWithObject();
	const char* mName;
	Vector2 mPos;
	Vector2 mRot;
	Vector2 mScale;
	Vector2 mVelocity;
	Rectangle mCollisionBox;
	u8 mIndex;
	u8 mCollision;
};

extern GameObject* objPool[255]; 
