#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    float get_x();
    float get_y();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
