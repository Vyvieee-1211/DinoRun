#include <SDL.h>
#include <SDL_image.h>
#include"renderWindow.h"
#include"background.h"
#include"mainObject.h"
#include"obstacle.h"
#include"defs.h"
#undef main

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));
    Graphics graphics;
    graphics.initSDL();
    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_FILE)); 
    SDL_Event event;
    MainObject dino;
    dino.init(graphics.loadTexture(DINO_FILE),DINO_FRAMES,DINO_CLIPS); 
    bool quit = 0; 
    HandleCactus handleCactus(5); 
    int dem = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&event)!= 0)
        {
            if (event.type == SDL_QUIT) quit = 1;
            dino.handleInputEvent(event); 
        }
        //std::cout << dem << std::endl;
        if (SDL_GetTicks() % 100 == 0) handleCactus.spawn(graphics);
        graphics.prepareScene();
        background.scroll(5); 
        graphics.render(background);
        handleCactus.update(graphics);
        dino.move();
        dino.show(graphics);
        graphics.presentScene();
        dem++; 
        SDL_Delay(16);
    }
    

    graphics.quit();
    return 0;
}
