#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
class ScrollingBackground
{
private:
	SDL_Texture* texture;
	int width = SCREEN_WIDTH ; 
	int height = SCREEN_HEIGHT; 
	int scrollingOffset = 0;

public:
	ScrollingBackground(); 
	~ScrollingBackground();
	SDL_Texture* getTexture()const;
	void setTexture(SDL_Texture* p_texture);
	void scroll(int distance); 
	int getScrollingOffset()const;
	int getWidth()const;
};