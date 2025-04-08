#include<SDL.h>
#include"game.h"
#undef main

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));
    Game DinoRun; 
    DinoRun.init();
    bool quit; 
    quit = DinoRun.getQuit();
    while (!quit)
    {
        DinoRun.play(); 
        quit = DinoRun.getQuit();
    }
    DinoRun.graphics->quit(); 
    return 0;
}
