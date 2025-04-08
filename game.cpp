#include"game.h"
Game::Game()
{
    graphics->initSDL();
}
void Game::reset()
{
    *speed = 5;
    *count = 0;
    *score = 0;
    *quit = 0;
    *hurt = 0;
    lastUpdateTime = SDL_GetTicks();
    dino->reset();
    handleCactus->reset();
}
void Game::init()
{
    background->setTexture(graphics->loadTexture(BACKGROUND_FILE));
    dino->init(graphics->loadTexture(DINO_FILE), graphics->loadTexture(DINO_HURT_FILE));
    menuText->init(graphics);
    getScore->init(graphics);
    sound->init();
    menu = graphics->loadTexture(MENU_FILE);
    menuLose = graphics->loadTexture(LOSE_FILE);
    handleCactus->init(graphics);
    sound->playMusic(hurt);
}
void Game::showMenu()
{
    graphics->renderTexture(menu, 0, 0);
    const char* text = "PRESS SPACE TO PLAY GAME";
    menuText->show(text, graphics, 300, 300); 
    graphics->presentScene();
}
void Game::showReplay()
{
    graphics->renderTexture(menuLose, 0, 0);
    graphics->presentScene();
}
void Game::play()
{
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT) *quit = 1;
        if (*gameStatus == 0)
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:

                    *gameStatus = 1;
                    break;
                case SDLK_ESCAPE:
                    *quit = 1;
                    break;
                }

            }
        }
        if (*gameStatus == 1)
            dino->handleInputEvent(event, sound);
        if (*gameStatus == 2)
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    *quit = 1;
                    break;
                case SDLK_SPACE:
                    *gameStatus = 0;
                    break;
                }

            }
        }

    }
    if (*gameStatus == 0)
    {
        showMenu();
    }
    if (*gameStatus == 1)
    {

        if (collision->check(dino, handleCactus))
        {
            *speed = 0;
            *hurt = 1;
            ++*gameStatus;
            sound->playEndGameSound();
            sound->playMusic(hurt);
        }
        if (SDL_GetTicks() - lastUpdateTime > 100) {
            if (*hurt == 0)
            {
                ++*score;
                lastUpdateTime = SDL_GetTicks();
            }
        }
        if (*hurt == 0 && *count % 100 == 0)
        {
            handleCactus->spawn(graphics);
        }
        graphics->prepareScene();
        background->scroll(*speed);
        graphics->render(background);
        handleCactus->update(graphics);
        dino->move();
        dino->show(graphics, hurt);
        getScore->show(graphics, score);
        graphics->presentScene();
        ++*count;
    }
    if (*gameStatus == 2 && *quit != 1)
    {
        showReplay();
        reset();
    }
    SDL_Delay(16);
}
bool Game::getQuit()
{
    return *quit;
}