#pragma once

#include <iostream>
#include "raylib.h"
#include "GameObject.h"
#include "ScoreManager.h"

enum GameStates {
	GAME_MAIN = 0,
	GAME_END = 1,
	GAME_TITLE = 2,
};

class GameManager {
public:
	GameManager();
	~GameManager();

	void ClearGameObj();
	void InitGameObj();
	void GameStateTitleInit();
	void GameStateMainInit();
	void GameStateEndInit();
	void Update();
	ScoreManager* scoreManager;
	bool mIsNotTransitioned;
};
extern GameManager* gameManager;

extern GameStates currentState;
