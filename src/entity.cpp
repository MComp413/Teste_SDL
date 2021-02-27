#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "Entity.hpp"
#include "Math.hpp"

using namespace std;

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture)
    :position(Vector2f(p_x, p_y)), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture)
    :position(p_position), texture(p_texture)
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

Vector2f& Entity::getPosition()
{
    return position;
}

float Entity::getX()
{
    return position.x;
}

float Entity::getY()
{
    return position.y;
}