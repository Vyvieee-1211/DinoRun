#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
const int SCREEN_WIDTH = 928;
const int SCREEN_HEIGHT = 522;
const int GROUND_HEIGHT = 102;//
const int DINO_WIDTH = 80, DINO_HEIGHT = 80;
const int SINGLE_CACTUS_WIDTH = 40, DOUBLE_CACTUS_WIDTH = 80, CACTUS_HEIGHT = 80;
const char BACKGROUND_FILE[] = "img/bg1.png";
const char SINGLE_CACTUS_FILE[] = "img/cactus.png";
const char DOUBLE_CACTUS_FILE[] = "img/double-cactus.png";
const char DINO_FILE[] = "img/DinoBlue.png"; 
const char DINO_HURT_FILE[] = "img/dinohurt.png";
const char MENU_FILE[] = "img/menu.png";
const char LOSE_FILE[] = "img/lose.png";
#define WINDOW_TITLE "Dino Run"
const int DINO_CLIPS[][4] = {
    {0, 0, 57, 57},
    {57, 0, 57,57},
    {114, 0, 57, 57},
    {171, 0, 57, 57},
    {228, 0, 57,57},
    {285, 0, 57,57}
};
const int DINO_FRAMES = sizeof(DINO_CLIPS) / sizeof(int) / 4;
const int DINO_HURT_FRAMES = 3; 
const int DINO_HURT_CLIPS[][4] = {
    {0, 0, 57, 57},
    {57, 0, 57,57},
    {114, 0, 57, 57},
};
const char FONT[] = "font/pixel_font.ttf";
const char BACKGROUND_MUSIC[] = "sound/sound_background.mp3"; 
const char END_GAME_SOUND[] = "sound/die_sound.mp3";
const char JUMP_SOUND[] = "sound/jump_sound.wav";