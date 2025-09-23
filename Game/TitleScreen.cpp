#include <iostream>
#include "raylib.h"
#include "GameObject.h"
#include "TitleScreen.h"
#include "ScoreManager.h"
#include "GameManager.h"


TitleScreen::TitleScreen() : GameObject({0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, "TitleScreen") {

}

TitleScreen::~TitleScreen() {}

void TitleScreen::Init() {

}

void TitleScreen::Draw() {
	DrawText("PONG", 167, 100, 180, GRAY);
	DrawText("PRESS ENTER TO PLAY!", 200, 350, 30, DARKBLUE);
	DrawText("PRESS ESCAPE TO EXIT", 200, 425, 30, DARKBLUE);

	DrawText("CREATED BY THEPLAYERROLO WITH RAYLIB", 50, 550, 30, DARKBLUE);


}

void TitleScreen::Update() {
	if (IsKeyPressed(KEY_ESCAPE)) {
		CloseWindow();
	}
	if (IsKeyPressed(KEY_ENTER)) {
		gameManager->GameStateMainInit();
	}
}