#include<SDL.h>
#include<SDL_image.h>
#include"renderWindow.h"
void Graphics::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}
void Graphics::initSDL()
{
    TTF_Init();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) logErrorAndExit("SDL_INIT", SDL_GetError());
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logErrorAndExit("Window error", SDL_GetError());
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit("SDL_image error:", IMG_GetError());
    if (TTF_Init() == -1) {
        logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
            TTF_GetError());
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        logErrorAndExit("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
            Mix_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) logErrorAndExit("Create Renderer", SDL_GetError());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void Graphics::prepareScene(SDL_Texture* background)
{
    SDL_RenderClear(renderer);
    if (background != nullptr)
    SDL_RenderCopy(renderer, background, NULL, NULL);
}
void Graphics::presentScene()
{
    SDL_RenderPresent(renderer); 
}
SDL_Texture* Graphics::loadTexture(const char* filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL)
        logErrorAndExit("Loading image %s", IMG_GetError());
    return texture;
}
TTF_Font* Graphics::loadFont(int size)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading font");
    TTF_Font* gFont = TTF_OpenFont(FONT, size);
    if (gFont == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Error Load font %s", TTF_GetError());
    }
    return gFont; 
}

void Graphics::renderTexture(SDL_Texture* texture, int x, int y, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    if(h != NULL)
    rect.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Graphics::render(const ScrollingBackground* bgr)
{ 
    renderTexture(bgr->getTexture(), bgr->getScrollingOffset(), 0, SCREEN_HEIGHT);
    renderTexture(bgr->getTexture(), bgr->getScrollingOffset() - bgr->getWidth(), 0, SCREEN_HEIGHT);
}
SDL_Renderer* Graphics::getRenderer()
{
    return renderer;
}

SDL_Texture* Graphics::renderText(TTF_Font* gFont, const char* text, SDL_Color& textColor)
{
    SDL_Surface* textSurface =
        TTF_RenderText_Solid(gFont, text, textColor);
    if (textSurface == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Render text surface %s", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(renderer, textSurface);
    if (texture == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Create texture from text %s", SDL_GetError());
    }
    SDL_FreeSurface(textSurface);
    return texture;
}
void Graphics::quit()
{
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit(); 
    Mix_Quit();
}