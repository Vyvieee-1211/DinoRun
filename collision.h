#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
#include"mainObject.h"
#include"obstacle.h"
struct Collision
{
	SDL_Rect dino;
	SDL_Rect obstacle;
	bool check(MainObject& mainObject, HandleCactus& obstacles);
};