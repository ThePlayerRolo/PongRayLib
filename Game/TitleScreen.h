#pragma once

#include <iostream>
#include "raylib.h"
#include "GameObject.h"
#include "ScoreManager.h"

class TitleScreen : public GameObject {
public:
	TitleScreen();
	~TitleScreen();
	virtual void Init();
	virtual void Draw();
	virtual void Update();

};