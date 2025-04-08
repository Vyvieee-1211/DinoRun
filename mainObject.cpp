#include<SDL.h>
#include<SDL_image.h>
#include"mainObject.h"

MainObject::MainObject()
{
	currentFrame = 0;
    currentFrame2 = -1;
	jump = 0;
    xPos = 50;
	yPos = 340;
    atRange = 1;
    onGround = 1; 
    delay = 0;
    SDL_Rect clip;
    for (int i = 0; i < DINO_HURT_FRAMES; i++)
    {
        clip.x = DINO_HURT_CLIPS[i][0];
        clip.y = DINO_HURT_CLIPS[i][1];
        clip.w = DINO_HURT_CLIPS[i][2];
        clip.h = DINO_HURT_CLIPS[i][3];
        hurtClips.push_back(clip);
    }
    for (int i = 0; i < DINO_FRAMES; i++)
    {
        clip.x = DINO_CLIPS[i][0];
        clip.y = DINO_CLIPS[i][1];
        clip.w = DINO_CLIPS[i][2];
        clip.h = DINO_CLIPS[i][3];
        clips.push_back(clip);
    }
}
void MainObject::reset()
{
    currentFrame = 0;
    currentFrame2 = -1;
    jump = 0;
    xPos = 50;
    yPos = 340;
    atRange = 1;
    onGround = 1;
    delay = 0;
}
bool MainObject::init(SDL_Texture* _texture, SDL_Texture* _hurtTexture)
{
    texture = _texture;
    hurtTexture = _hurtTexture; 
    currentFrame = 0;
    currentFrame2 = -1;
    jump = 0;
    xPos = 50;
    yPos = 340;
    atRange = 1;
    onGround = 1;
    delay = 0;
    SDL_Rect clip;
    for (int i = 0; i < DINO_HURT_FRAMES; i++)
    {
        clip.x = DINO_HURT_CLIPS[i][0];
        clip.y = DINO_HURT_CLIPS[i][1];
        clip.w = DINO_HURT_CLIPS[i][2];
        clip.h = DINO_HURT_CLIPS[i][3];
        hurtClips.push_back(clip);
    }
    for (int i = 0; i < DINO_FRAMES; i++)
    {
        clip.x = DINO_CLIPS[i][0];
        clip.y = DINO_CLIPS[i][1];
        clip.w = DINO_CLIPS[i][2];
        clip.h = DINO_CLIPS[i][3];
        clips.push_back(clip);
    }
    if (texture == nullptr || hurtTexture == nullptr) return 0;
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
void MainObject::handleInputEvent(SDL_Event events, Sound* sound)
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
                sound->playJumpSound(); 
            } 
        }

    }
}

void MainObject::show(Graphics* graphics, bool* hurt)
{
    SDL_Rect* currentClip;
    if (*hurt == 1)
    {
        if (currentFrame2 < 2)
            currentFrame2++; 
        currentClip = &hurtClips[currentFrame2];
        renderQuad = { xPos,yPos, DINO_WIDTH, DINO_HEIGHT };
        SDL_RenderCopy(graphics->getRenderer(), hurtTexture, currentClip, &renderQuad);
    }
    else
    {
        if (jump == 0)
        {
            delay++;
            if (delay == 4)
            {
                currentFrame = (currentFrame + 1) % DINO_FRAMES;
                delay = 0;
            }
        }
        else currentFrame = 2;
        currentClip = &clips[currentFrame];
        renderQuad = { xPos,yPos, DINO_WIDTH, DINO_HEIGHT };
        SDL_RenderCopy(graphics->getRenderer(), texture, currentClip, &renderQuad);
    }
}
SDL_Rect MainObject::getRect()
{
    return renderQuad; 
}