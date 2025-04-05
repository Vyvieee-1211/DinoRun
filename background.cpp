#include<SDL.h>
#include<SDL_image.h>
#include"background.h"
ScrollingBackground::ScrollingBackground()
{
    width = SCREEN_WIDTH;
    height = SCREEN_HEIGHT;
}
ScrollingBackground::~ScrollingBackground()
{

}
void ScrollingBackground::setTexture(SDL_Texture* p_texture)
{
    texture = p_texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}
void ScrollingBackground::scroll(int distance)//distance quyết định tốc độ
{
    scrollingOffset -= distance;
    if (scrollingOffset < 0) { scrollingOffset = width; }
}
SDL_Texture* ScrollingBackground::getTexture() const
{
    return texture; 
}
int ScrollingBackground::getScrollingOffset()const
{
    return scrollingOffset;
}
int ScrollingBackground::getWidth()const
{
    return width;
}
