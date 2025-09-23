#include "Ball.h"
#include "Paddle.h"
#include "raylib.h"
#include <iostream>
#include "../types.h"
#include "ScoreManager.h"
#include "GameManager.h"

Ball::Ball(Vector2 startPos) : GameObject(startPos, { startPos.x - 10, startPos.y - 10, 20.0f, 20.0f }, "Ball") {
	mRadius = 0.0f;
	isNextPlayer = false;
}

Ball::~Ball() {

}

void Ball::Init() {
	mRadius = 10.0f;
	mVelocity.x = -5.0f;
	mVelocity.y = 0.0f;
	isNextPlayer = false;

}

void Ball::Draw() {
	DrawCircleV(mPos, mRadius, MAROON);

	//DrawRectangle(mCollisionBox.x, mCollisionBox.y, mCollisionBox.width, mCollisionBox.height, GetColor(0x491973));
}

void Ball::Update() {
	if ((mCollisionBox.x + mCollisionBox.width) >= (GetScreenWidth() - 10)) {
		isNextPlayer = false;
		gameManager->scoreManager->Score(true);
	}

	if ((mCollisionBox.x + mCollisionBox.width) <= 0.0f) {
		isNextPlayer = true;
		gameManager->scoreManager->Score(false);
	}

	if (isCollidedWithObject()) {
		mVelocity.x *= -1.0f;
		f32 paddleY = objPool[mCollision]->mPos.y + 45.0f;
		f32 ballY = mPos.y;

		if (ballY < paddleY - 20) {
			mVelocity.y = 5.0f;
		} else if (ballY > paddleY + 20) {
			mVelocity.y = -5.0f;
		}
		else {
			mVelocity.y = 0.0f;
		}

		mCollision = -1;
	}
	if ((mCollisionBox.y + mCollisionBox.height) >= (GetScreenHeight()) || mCollisionBox.y <= 0.0f) {
		mVelocity.y *= -1.0f;
	}
	mRadius *= mScale.x;
	mPos.x += mVelocity.x;
	mPos.y += mVelocity.y;
	mCollisionBox.x = mPos.x - 10;
	mCollisionBox.y = mPos.y - 10;

}

void Ball::onScore() {
	mPos.x = 400.0f;
	mPos.y = 300.0f;
	if (isNextPlayer) { mVelocity.x = -5.0f; }
	else { mVelocity.x = 5.0f; }
	mVelocity.y = 0;

	mCollisionBox.x = mPos.x - 10;
	mCollisionBox.y = mPos.y - 10;
}