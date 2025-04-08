#include<SDL.h>
#include <SDL_image.h>
#include"renderWindow.h"
#include"background.h"
#include"mainObject.h"
#include"obstacle.h"
#include"defs.h"
#include"collision.h"
#include"text.h"
#include"sound.h"
struct Game
{
    int *speed = new int(5), * count = new int(0), * score = new int(0);
    bool* quit = new bool(0), * hurt = new bool(0);
    int *gameStatus = new int(0);
    Graphics *graphics = new Graphics;
    Uint32 lastUpdateTime = SDL_GetTicks();
    ScrollingBackground *background = new ScrollingBackground;
    SDL_Event event;
    MainObject *dino = new MainObject;
    HandleCactus *handleCactus = new HandleCactus(speed);
    Collision *collision = new Collision;
    Sound *sound = new Sound;
    Text *menuText = new Text;
    Score *getScore = new Score;
    SDL_Texture* menu;
    SDL_Texture* menuLose;
    Game();
    void reset();
    void init();
    void showMenu();
    void showReplay();
    void play();
    bool getQuit();
};
