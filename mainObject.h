#pragma once
#include"defs.h"
#include"renderWindow.h"
#include<vector>
#include"sound.h"
class MainObject
{
private:
	SDL_Texture* texture;
	SDL_Texture* hurtTexture;
	SDL_Rect renderQuad;
	std::vector<SDL_Rect> clips;
	std::vector<SDL_Rect> hurtClips;
	int currentFrame;
	int currentFrame2; 
	bool jump; 
	const int jumpValue = 12; 
	const int jumpRange = 220;
	bool atRange; 
	bool onGround; 
	int xPos;// xpos nay k thay doi
	int yPos; //vi tri render
	int delay;

public:
	MainObject();
	~MainObject();
	bool init(SDL_Texture* _texture,SDL_Texture* _hurtTexture);
	void move(); 
	void handleInputEvent(SDL_Event events);
	void show(Graphics& graphics, bool* hurt);
	SDL_Rect getRect();

};