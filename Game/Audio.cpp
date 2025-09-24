#include "raylib.h"
#include <iostream>
#include "Audio.h"

Sound SOUND_TADA;
Sound SOUND_HIT;
Sound SOUND_ENTER;

void InitSounds() {
	SOUND_TADA = LoadSound("assets/audio/Tada.ogg");
	SOUND_ENTER = LoadSound("assets/audio/Enter.ogg");
	SOUND_HIT = LoadSound("assets/audio/Hit.ogg");

}

void UnloadSounds() {
	UnloadSound(SOUND_TADA);
	UnloadSound(SOUND_ENTER);
	UnloadSound(SOUND_HIT);

}