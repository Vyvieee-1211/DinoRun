#include<SDL.h>
#include"getScore.h"
Score::Score(Graphics& graphics)
{
	gFont = graphics.loadFont(30);
}
Score::~Score()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}
void Score::show(int* score, Graphics& graphics)
{
	std::string scoreStr = std::to_string(*score);
	scoreStr = "score: " + scoreStr;
	const char* text = scoreStr.c_str();
	texture = graphics.renderText(gFont, text, textColor);
	graphics.renderTexture(texture, 30, 30); 
}