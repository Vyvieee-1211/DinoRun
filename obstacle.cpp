#include<SDL.h>
#include<SDL_image.h>
#include"obstacle.h"
Cactus::Cactus(int _speed, int _random, SDL_Texture* _obstacle)
{
	xPos = SCREEN_WIDTH;
	yPos = SCREEN_HEIGHT - GROUND_HEIGHT - CACTUS_HEIGHT;
	speed = _speed;
	random = _random;
	width = (random == 1) ? SINGLE_CACTUS_WIDTH : DOUBLE_CACTUS_WIDTH; 
}
int Cactus::move(int speed)
{
	return xPos -= speed;
}
void Cactus::show(Graphics& graphics)
{
	SDL_Rect renderQuad;
	if (random == 1)
	{
		renderQuad = { move(speed), yPos, SINGLE_CACTUS_WIDTH, CACTUS_HEIGHT };
	}
	else
	{
		renderQuad = { move(speed), yPos, DOUBLE_CACTUS_WIDTH, CACTUS_HEIGHT };
	}
	SDL_RenderCopy(graphics.getRenderer(), singleCactus, NULL, &renderQuad);
}
int Cactus::getWidth()
{
	return width; 
}
HandleCactus::HandleCactus(int _speed)
{
	speed = _speed;
}
void HandleCactus::init(Graphics& graphics)
{
	singleCactus = graphics.loadTexture(SINGLE_CACTUS_FILE);
	doubleCactus = graphics.loadTexture(DOUBLE_CACTUS_FILE);
	bat = graphics.loadTexture(BAT_FILE); 
}
int HandleCactus::random()
{
	return 1 + rand() % 3;
}
void HandleCactus::spawn(Graphics& graphics)
{
	int randValue = random();
	switch (randValue)
	{
	case 1:

	case 2:
	case 3:
	}
}
void HandleCactus::update(Graphics& graphics)
{
	if (!obstacles.empty())
	{
		if (obstacles[0].move(speed) + obstacles[0].getWidth() < 0)
			obstacles.erase(obstacles.begin());
	}
	for (auto& obstacle : obstacles)
		obstacle.show(graphics);
}