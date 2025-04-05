#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"defs.h"
#include"background.h"
#include<vector>
class Graphics {
private:
	SDL_Window* window;
	SDL_Renderer* renderer; 
public:
	SDL_Texture* loadTexture(const char* filename);
	void logErrorAndExit(const char* msg, const char* error); 
	void initSDL();
	void prepareScene(SDL_Texture* background = nullptr);
	void presentScene();
	void renderTexture(SDL_Texture* texture, int x = NULL, int y = NULL);// render vao vi tri (x,y)
	void render(const ScrollingBackground& bgr);
	void quit();
	SDL_Renderer* getRenderer();
};

