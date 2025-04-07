#include <SDL.h>
#include <SDL_image.h>
#include"renderWindow.h"
#include"background.h"
#include"mainObject.h"
#include"obstacle.h"
#include"defs.h"
#include"collision.h"
#include"getScore.h"
#undef main

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));
    int speed = 5, count = 0, score = 0; 
    bool quit = 0, hurt = 0; 
    Graphics graphics;
    graphics.initSDL();
    Uint32 lastUpdateTime = SDL_GetTicks();
    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_FILE)); 
    SDL_Event event;
    MainObject dino;
    dino.init(graphics.loadTexture(DINO_FILE),graphics.loadTexture(DINO_HURT_FILE)); 
    HandleCactus handleCactus(&speed); 
    handleCactus.init(graphics);
    Collision collision; 
    Score getScore(graphics); 
    while (!quit)
    {
        while (SDL_PollEvent(&event)!= 0)
        {
            if (event.type == SDL_QUIT) quit = 1;
            dino.handleInputEvent(event); 
        }
        if (collision.check(dino, handleCactus))
        {
            speed = 0; 
            hurt = 1;
        }
        if (count % 100 == 0)
        {
            handleCactus.spawn(graphics);
        }
        if (SDL_GetTicks() - lastUpdateTime > 100) {
            if (hurt == 1) continue; 
            score++;
            lastUpdateTime = SDL_GetTicks();
        }
        graphics.prepareScene();
        background.scroll(0); 
        graphics.render(background);
        handleCactus.update(graphics);
        dino.move();
        dino.show(graphics, &hurt);
        getScore.show(&score, graphics); 
        graphics.presentScene();
        count++; 
        SDL_Delay(16);
    }
    

    graphics.quit();
    return 0;
}
