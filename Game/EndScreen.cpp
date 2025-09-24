#include <iostream>
#include "raylib.h"
#include "GameObject.h"
#include "EndScreen.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "Audio.h"

EndScreen::EndScreen() : GameObject({0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, "EndScreen") {
	mFinalScoreData.mCPUPoints = -1;
	mFinalScoreData.mPlayerPoints = -1;
	mFinalScoreData.mDidPlayerWin = false;

};
EndScreen::~EndScreen() {};

void EndScreen::Init() {
	mFinalScoreData = gameManager->scoreManager->mScoreData;
}

void EndScreen::Draw() {
	if (mFinalScoreData.mDidPlayerWin) {
		DrawText("YOU WON!", 250, 100, 60, GREEN);
	}
	else {
		DrawText("YOU LOST!", 250, 100, 60, RED);
	}
	DrawText(TextFormat("YOUR SCORE: %d",mFinalScoreData.mPlayerPoints), 75, 200, 40, DARKBLUE);
	DrawText(TextFormat("CPU SCORE: %d", mFinalScoreData.mCPUPoints), 450, 200, 40, DARKBLUE);
	DrawText("THANK YOU FOR PLAYING!", 150, 300, 40, DARKBLUE);
	DrawText("PRESS ESCAPE TO EXIT", 200, 450, 30, DARKBLUE);
	DrawText("PRESS ENTER TO RETURN TO MAIN MENU", 75, 525, 30, DARKBLUE);


}

void EndScreen::Update() {
	printf("gameManager->CurrentState: %d", currentState);

	if (IsKeyPressed(KEY_ESCAPE)) {
		CloseWindow();
	}
	if (IsKeyPressed(KEY_ENTER)) {
		PlaySound(SOUND_ENTER);
		gameManager->mIsNotTransitioned = true;
		currentState = GAME_TITLE;
	}
}