#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
#include"renderWindow.h"
#include<vector>
class MainObject
{
private:
	SDL_Texture* texture;
	std::vector<SDL_Rect> clips;
	int currentFrame;
	bool jump; 
	const int jumpValue = 5; 
	const int jumpRange = 230;//110  
	bool atRange; 
	bool onGround; 
	int xPos;// xpos nay k thay doi
	int yPos; //vi tri render
	int delay = 0;

public:
	MainObject();
	~MainObject();
	bool init(SDL_Texture* _texture,const int frames, const int _clip[][4]);
	void move(); 
	void handleInputEvent(SDL_Event events);
	void show(Graphics& graphics);

};