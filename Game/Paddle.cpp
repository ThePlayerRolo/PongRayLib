#include "Ball.h"
#include "Paddle.h"
#include "raylib.h"
#include <iostream>
#include "../types.h"


Paddle::Paddle(Vector2 startPos, bool isPlayer, const char* pName) : GameObject(startPos, { startPos.x, startPos.y, 20.0f, 90.0f }, pName) {
	mVisibleWH.x = 0.0f;
	mVisibleWH.y = 0.0f;
	mIsPlayer = isPlayer;
	mCurBall = nullptr;
	mStartPos = startPos;
}

Paddle::~Paddle() {
	mCurBall = nullptr;
}
void Paddle::Init() {
	mVisibleWH.x = mCollisionBox.width;
	mVisibleWH.y = mCollisionBox.height;
	if (!mIsPlayer) {
		CPUFindBall();
	}
}

void Paddle::Draw() {
	DrawRectangle(mPos.x, mPos.y, mVisibleWH.x, mVisibleWH.y, DARKGRAY);
}

void Paddle::doPlayerInputs() {
	if ((mCollisionBox.y + mCollisionBox.height) >= 150.0f) {
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) mVelocity.y = -5.0f;
	}
	if ((mCollisionBox.y + mCollisionBox.height) <= (GetScreenHeight() - 50.0f)) {
		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) mVelocity.y = 5.0f;
	}
}

void Paddle::CPUFindBall() {
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] != nullptr) {
			if (objPool[i]->mName == "Ball") {
				mCurBall = (Ball*)objPool[i];
				break;
			}
		}
	}
}

void Paddle::doCpuInputs() {

	f32 CurPos = mPos.y;
	if (mCurBall->mPos.y > (CurPos + 10)) {
		if ((mCollisionBox.y + mCollisionBox.height) <= (GetScreenHeight() - 50.0f)) {
			mVelocity.y = 3.75f;
		}
	}
	else if (mCurBall->mPos.y <= (CurPos - 10)) {
		if ((mCollisionBox.y + mCollisionBox.height) >= 150.0f) {
			mVelocity.y = -3.75f;
		}
	}


}

void Paddle::Update() {
	if (mIsPlayer) {
		doPlayerInputs();
	}
	else {
		doCpuInputs();
	}
	mPos.y += mVelocity.y;
	mCollisionBox.y += mVelocity.y;
	mVelocity.y = 0;
}

void Paddle::onScore() {
	if (!mIsPlayer) {
		mPos = mStartPos;
		mCollisionBox.x = mPos.x;
		mCollisionBox.y = mPos.y;
		mVelocity.y = 0;
	}
}