#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "Entity.hpp"

using namespace std;

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture)
    :x(p_x), y(p_y), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}

float Entity::get_x()
{
    return x;
}

float Entity::get_y()
{
    return y;
}