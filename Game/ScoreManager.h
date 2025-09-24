#pragma once

#include <iostream>
#include "raylib.h"
#include "../types.h"

typedef struct ScoreData {
	u8 mPlayerPoints;
	u8 mCPUPoints;
	bool mDidPlayerWin;
} ScoreData;

class ScoreManager {
public:
	ScoreManager();
	~ScoreManager();
	void Init();
	void Update();
	void Draw();
	void Score(bool);
	ScoreData mScoreData;
	bool IsGameDone;
};
