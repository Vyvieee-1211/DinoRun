#pragma once
#include<SDL.h>
#include"defs.h"
#include<SDL_mixer.h>

class Sound
{
private:
    Mix_Music* gMusic; 
    Mix_Chunk* jumpingSound; 
    Mix_Chunk* endGameSound;
public:
    void init();
    void playMusic(bool* hurt);
    void playJumpSound();
    void playEndGameSound();
};