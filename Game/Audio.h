#pragma once

#include <iostream>
#include "raylib.h"

enum SOUND_FILE {
	SOUND_INVALID = -1,
	SOUND_TADA = 0,
	SOUND_HIT = 1,
	SOUND_ENTER = 2,
	SOUND_COUNT = 3,
};

Sound soundTable[SOUND_COUNT];
