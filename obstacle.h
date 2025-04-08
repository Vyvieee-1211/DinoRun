#pragma once
#include<SDL.h>
#include"defs.h"
#include"renderWindow.h"
class Cactus
{
private:
	int random; 
	int xPos;
	int yPos;
	int *speed; 
	int width;
	SDL_Texture* obstacle;
	SDL_Rect renderQuad;
public:

	Cactus(int* _speed, int _random, SDL_Texture* _obstacle);
	int move(int *speed);
	void show(Graphics* graphics);
	SDL_Rect getRect();
	int getWidth();
};

struct HandleCactus
{
	SDL_Texture* singleCactus;
	SDL_Texture* doubleCactus;
	std::vector<Cactus> VectorObstacle;
	int *speed; 
	HandleCactus(int *_speed);
	void reset();
	void init(Graphics* graphics); 
	int random();
	void spawn(Graphics* graphics);
	void update(Graphics* graphics);
};