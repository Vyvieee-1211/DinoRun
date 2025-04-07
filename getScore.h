#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>
#include"defs.h"
#include"renderWindow.h"

class Score
{
private:
	TTF_Font* gFont;
	SDL_Texture* texture;
	SDL_Color textColor = { 0, 0, 0, 255 }; 
public:
	Score(Graphics& graphics);
	void show(int* score, Graphics& graphics); 
};