#include "GameObject.h"
#include "raylib.h"
#include <iostream>

GameObject* objPool[255];

GameObject::GameObject(Vector2 startPos, Rectangle collisonBox, const char* pName) {
	mScale = { 1.0f, 1.0f };
	mVelocity = mRot = { 0.0f, 0.0f };
	mPos = startPos;
	mCollisionBox = collisonBox;
	mIndex = -1;
	mCollision = -1;
	mName = pName;
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] == nullptr) {
			objPool[i] = this;
			mIndex = i;
			break;
		}
	}
	
}

GameObject::~GameObject() {
	objPool[mIndex] = nullptr;
}

void GameObject::Init() {

}

void GameObject::Draw() {

}

void GameObject::Update() {

}

void GameObject::onScore() {

}


bool GameObject::isCollidedWithObject() {
	bool isCollided = false;
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] != nullptr && i != mIndex) {
			if (CheckCollisionRecs(this->mCollisionBox, objPool[i]->mCollisionBox)) {
				isCollided = true;
				mCollision = i;
				break;
			}
		}
	}
	return isCollided;
}