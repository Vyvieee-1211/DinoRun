#include<SDL.h>
#include<SDL_image.h>
#include"mainObject.h"

MainObject::MainObject()
{
	currentFrame = 0;
	jump = 0;
    xPos = 50;
	yPos = 340;
    atRange = 1;
    onGround = 1; 
}
MainObject::~MainObject()
{

}
bool MainObject::init(SDL_Texture* _texture,const int frames, const int _clip[][4])
{
    SDL_Rect clip;
    texture = _texture;
    for (int i = 0; i < frames; i++)
    {
        clip.x = _clip[i][0];
        clip.y = _clip[i][1];
        clip.w = _clip[i][2];
        clip.h = _clip[i][3];
        clips.push_back(clip);
    }
    if (texture == nullptr) return 0;
    return 1; 
}
void MainObject::move()
{
    if (jump == 1)
    {
        if (atRange == 1)
        {
            yPos += jumpValue;
            if (SCREEN_HEIGHT - yPos - DINO_HEIGHT < GROUND_HEIGHT)
            {
                yPos = SCREEN_HEIGHT - GROUND_HEIGHT - DINO_HEIGHT;
                jump = 0;
                onGround = 1;
            }
        }
        else
        {
           yPos -= jumpValue;
            if (yPos <= jumpRange)
            {
                atRange = 1;
                yPos = jumpRange;
            }
        }
    }
}
void MainObject::handleInputEvent(SDL_Event events)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_SPACE:
            if (jump == 0 && onGround == 1) {
                jump = 1; onGround = 0;
                atRange = 0; 
            } 
        }

    }
}

void MainObject::show(Graphics& graphics)
{
    if (jump == 0)
    {
        delay++; 
        if (delay == 4)
        {
            currentFrame = (currentFrame + 1) % clips.size();
            delay = 0;
        }
    }
    else currentFrame = 2; 
    SDL_Rect* currentClip = &clips[currentFrame];
    SDL_Rect renderQuad = { xPos,yPos, DINO_WIDTH, DINO_HEIGHT};
    /*std::cout << yPos << '\n';*/
    SDL_RenderCopy(graphics.getRenderer(), texture, currentClip, &renderQuad);
}