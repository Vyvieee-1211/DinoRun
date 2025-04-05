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
	int speed; 
	int width;
	SDL_Texture* obstacle;
public:

	Cactus(int _speed, int _random);
	int move(int speed);
	void show(Graphics& graphics);
	int getWidth(); 
};

struct HandleCactus
{
	SDL_Texture* singleCactus;
	SDL_Texture* doubleCactus;
	SDL_Texture* bat; 
	std::vector<Cactus> obstacles;
	int speed; 
	HandleCactus(int _speed);
	void init(Graphics& graphics); 
	int random();
	void spawn(Graphics& graphics);
	void update(Graphics& graphics);
};