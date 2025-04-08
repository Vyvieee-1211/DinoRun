#include<SDL.h>
#include<SDL_image.h>
#include"obstacle.h"
Cactus::Cactus(int* _speed, int _random, SDL_Texture* _obstacle)
{
	xPos = SCREEN_WIDTH;
	yPos = SCREEN_HEIGHT - GROUND_HEIGHT - CACTUS_HEIGHT;
	speed = _speed;
	random = _random;
	width = (random == 1) ? SINGLE_CACTUS_WIDTH : DOUBLE_CACTUS_WIDTH; 
	obstacle = _obstacle;
}
int Cactus::move(int *speed)
{
	return xPos -= *speed;
}
void Cactus::show(Graphics* graphics)
{
	renderQuad;
	if (random == 1)
	{
		renderQuad = { move(speed), yPos, SINGLE_CACTUS_WIDTH, CACTUS_HEIGHT };
	}
	else
	{
		renderQuad = { move(speed), yPos, DOUBLE_CACTUS_WIDTH, CACTUS_HEIGHT };
	}
	SDL_RenderCopy(graphics->getRenderer(), obstacle, NULL, &renderQuad);
}
SDL_Rect Cactus::getRect()
{
	return renderQuad;
	
}
int Cactus::getWidth()
{
	return width; 
}
HandleCactus::HandleCactus(int* _speed)
{
	speed = _speed;
}
void HandleCactus::reset()
{
	if (!VectorObstacle.empty())
	{
		VectorObstacle.erase(VectorObstacle.begin(), VectorObstacle.end());
	}
}
void HandleCactus::init(Graphics* graphics)
{
	singleCactus = graphics->loadTexture(SINGLE_CACTUS_FILE);
	doubleCactus = graphics->loadTexture(DOUBLE_CACTUS_FILE);
}
int HandleCactus::random()
{
	return 1 + rand() % 2;
}
void HandleCactus::spawn(Graphics* graphics)
{
	int randValue = random();
	if (randValue == 1)
	{
		Cactus obstacle(speed, 1, singleCactus);
		VectorObstacle.push_back(obstacle);
	}
	else
	{
		Cactus obstacle(speed, 2, doubleCactus);
		VectorObstacle.push_back(obstacle);
	}
}
void HandleCactus::update(Graphics* graphics)
{
	if (!VectorObstacle.empty())
	{
		if (VectorObstacle[0].move(speed) + VectorObstacle[0].getWidth() < 0)
			VectorObstacle.erase(VectorObstacle.begin());
	}
	for (auto& obstacle : VectorObstacle)
		obstacle.show(graphics);
}
