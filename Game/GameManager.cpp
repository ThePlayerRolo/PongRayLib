#include <iostream>
#include "raylib.h"
#include "../types.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "ScoreManager.h"
#include "EndScreen.h"
#include "TitleScreen.h"

GameManager* gameManager;

GameManager::GameManager() {
	scoreManager = nullptr;
	currentState = GAME_MAIN;
}

GameManager::~GameManager() {
	ClearGameObj();
}

void GameManager::ClearGameObj() {
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] != nullptr) {
			delete objPool[i];
		}
	}
}

void GameManager::InitGameObj() {
	for (u8 i = 0; i < 255; i++) {
		if (objPool[i] != nullptr) {
			objPool[i]->Init();
		}
	}
}

void GameManager::GameStateMainInit() {
	ClearGameObj();
	currentState = GAME_MAIN;
	if (scoreManager == nullptr) {
		scoreManager = new ScoreManager();
	}
	Ball* MainBall = new Ball({ 400.0f, 300.0f });
	Paddle* PlayerPaddle = new Paddle({ 50.0f, 250.0f }, true, "PlayerPaddle");
	Paddle* CPUPaddle = new Paddle({ 750.0f, 250.0f }, false, "CPUPaddle");
	scoreManager->Init();
	InitGameObj();
}

void GameManager::GameStateEndInit() {
	ClearGameObj();
	currentState = GAME_END;
	EndScreen* endScreen = new EndScreen();
	InitGameObj();
}

void GameManager::GameStateTitleInit() {
	ClearGameObj();
	currentState = GAME_TITLE;
	TitleScreen* titleScreen = new TitleScreen();
	InitGameObj();
}