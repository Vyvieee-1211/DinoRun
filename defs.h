#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

const int SCREEN_WIDTH = 928;
const int SCREEN_HEIGHT = 522;
const int GROUND_HEIGHT = 102;//
const int DINO_WIDTH = 80, DINO_HEIGHT = 80;
const int SINGLE_CACTUS_WIDTH = 40, DOUBLE_CACTUS_WIDTH = 80, CACTUS_HEIGHT = 80;
const char BACKGROUND_FILE[] = "bg1.png";
const char SINGLE_CACTUS_FILE[] = "cactus.png";
const char DOUBLE_CACTUS_FILE[] = "double-cactus.png";
const char DINO_FILE[] = "DinoBlue.png"; 
const char BAT_FILE[] = "bat.png"; 
#define WINDOW_TITLE "Dino Run ~ by Vy"
const int DINO_CLIPS[][4] = {
    {0, 0, 57, 57},
    {57, 0, 57,57},
    {114, 0, 57, 57},
    {171, 0, 57, 57},
    {228, 0, 57,57},
    {285, 0, 57,57}
};
const int DINO_FRAMES = sizeof(DINO_CLIPS) / sizeof(int) / 4;