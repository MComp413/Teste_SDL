#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

#include "Math.hpp"

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    Entity(Vector2f p_position, SDL_Texture* p_texture);
    Vector2f& getPosition();
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
