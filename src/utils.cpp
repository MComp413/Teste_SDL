#include <SDL2/SDL.h>
#include "Utils.hpp"

float utils::hireTimeInSeconds()
{
    float t;
    t = SDL_GetTicks();
    return t * 0.001f;
}