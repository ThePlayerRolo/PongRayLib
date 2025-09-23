
#include <iostream>
#include "raylib.h"
#include "../types.h"
#include "ScoreManager.h"
#include "GameObject.h"
#include "GameManager.h"

ScoreManager::ScoreManager() {
	mScoreData.mPlayerPoints = mScoreData.mCPUPoints = -1;
	mScoreData.mDidPlayerWin = false;
}

ScoreManager::~ScoreManager() {

}

void ScoreManager::Init() {
	mScoreData.mPlayerPoints = 0;
	mScoreData.mCPUPoints = 0;
	mScoreData.mDidPlayerWin = false;
}

void ScoreManager::Draw() {
	if (gameManager->currentState == GAME_MAIN) {
		DrawText(TextFormat("%d", mScoreData.mPlayerPoints), 200, 50, 60, DARKBLUE);
		DrawText(TextFormat("%d", mScoreData.mCPUPoints), 600, 50, 60, DARKBLUE);
	}
}

void ScoreManager::Update() {
	if (mScoreData.mPlayerPoints >= 10) {
		mScoreData.mDidPlayerWin = true;
		gameManager->GameStateEndInit();

	}
	else if (mScoreData.mCPUPoints >= 10) {
		mScoreData.mDidPlayerWin = false;
		gameManager->GameStateEndInit();
	}
}

void ScoreManager::Score(bool isPlayer) {
	if (isPlayer) {
		mScoreData.mPlayerPoints++;
	}
	else {
		mScoreData.mCPUPoints++;
	}
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] != nullptr) {
			objPool[i]->onScore();
		}
	}
}