#pragma once

#include <iostream>
#include "raylib.h"
#include "GameObject.h"
#include "ScoreManager.h"

class EndScreen : public GameObject {
public:
	EndScreen();
	virtual ~EndScreen();
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	ScoreData mFinalScoreData;
};