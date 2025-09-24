#include <iostream>
#include "raylib.h"
#include "Game/Game.h"

const s32 ScreenWidth = 800;
const s32 ScreenHeight = 600;

int main()
{
	InitWindow(ScreenWidth, ScreenHeight, "PONG");
	InitAudioDevice();
	SetTargetFPS(60);
	gameManager = new GameManager();
	gameManager->GameStateTitleInit();
	InitSounds();
	while (!WindowShouldClose()) {
		gameManager->Update();
		//Run all existing Object's Update functions
		for (u8 i = 0; i < 255; i++) {
			if (objPool[i] != nullptr) {
				objPool[i]->Update();
			}
		}
		//Hacky fix, idk if ScoreManager could work as a GameObject
		if (gameManager->scoreManager != nullptr) {
			gameManager->scoreManager->Update();
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (u8 i = 0; i < 255; i++) {
			if (objPool[i] != nullptr) {
				objPool[i]->Draw();
			}
		}
		if (gameManager->scoreManager != nullptr) {
			gameManager->scoreManager->Draw();
		}
		EndDrawing();
	}
	delete gameManager;
	UnloadSounds();
	CloseWindow();
	return 0;
}

