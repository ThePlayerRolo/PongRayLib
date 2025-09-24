
#include <iostream>
#include "raylib.h"
#include "../types.h"
#include "ScoreManager.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Audio.h"

ScoreManager::ScoreManager() {
	mScoreData.mPlayerPoints = mScoreData.mCPUPoints = -1;
	mScoreData.mDidPlayerWin = false;
	IsGameDone = false;
}

ScoreManager::~ScoreManager() {

}

void ScoreManager::Init() {
	mScoreData.mPlayerPoints = 0;
	mScoreData.mCPUPoints = 0;
	mScoreData.mDidPlayerWin = false;
	IsGameDone = false;
}

void ScoreManager::Draw() {
	if (currentState == GAME_MAIN) {
		DrawText(TextFormat("%d", mScoreData.mPlayerPoints), 200, 50, 60, DARKBLUE);
		DrawText(TextFormat("%d", mScoreData.mCPUPoints), 600, 50, 60, DARKBLUE);
	}
}

void ScoreManager::Update() {
	if (!IsGameDone) {
		if (mScoreData.mPlayerPoints >= 10) {
			mScoreData.mDidPlayerWin = true;
			gameManager->GameStateEndInit();
			IsGameDone = true;

		}
		else if (mScoreData.mCPUPoints >= 10) {
			mScoreData.mDidPlayerWin = false;
			gameManager->GameStateEndInit();
			IsGameDone = true;
		}
	}
}

void ScoreManager::Score(bool isPlayer) {
	PlaySound(SOUND_TADA);

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