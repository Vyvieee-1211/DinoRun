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
	std::string scoreStr;
public:
	void init(Graphics* graphic);
	/*const char* convertText(int* score);*/
	void show( Graphics* graphics, int* score); 
};
class Text
{
private:
	TTF_Font* menuText; 
	SDL_Texture* texture;
	SDL_Color textColor = { 0, 0, 0, 255 };
public:
	void init(Graphics* graphics);
	void show(const char* text, Graphics* graphics);
};