#include<SDL.h>
#include"text.h"
void Score::init(Graphics* graphics)
{
	gFont = graphics->loadFont(30);
}
void Score::show(Graphics* graphics, int* score)
{
	scoreStr = std::to_string(*score);
	scoreStr = "score: " + scoreStr;
	const char* text = scoreStr.c_str();
	texture = graphics->renderText(gFont, text, textColor);
	graphics->renderTexture(texture, 30, 30); 
}
void Text::init(Graphics* graphics)
{
	menuText = graphics->loadFont(50);
}
void Text::show(const char* text, Graphics* graphics, int xPos, int yPos)
{
	texture = graphics->renderText(menuText, text, textColor);
	graphics->renderTexture(texture, xPos, yPos);
}