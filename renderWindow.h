#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
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
	void renderTexture(SDL_Texture* texture, int x, int y, int h = NULL);// render vao vi tri (x,y)
	TTF_Font* loadFont(int size); 
	void render(const ScrollingBackground& bgr);
	SDL_Renderer* getRenderer();
	SDL_Texture* renderText(TTF_Font* gFont, const char* text, SDL_Color& textColor);
	void quit();
};

