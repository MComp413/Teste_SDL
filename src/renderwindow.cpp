#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if(window == NULL)
        cout << "Window failed to init. Error: " << SDL_GetError() << endl;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL)
        cout << "Failed to load texture. Error: " << SDL_GetError() << endl;
    
    return texture;
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect srcRectangle;
    SDL_Rect dstRectangle;

    srcRectangle.x = p_entity.getCurrentFrame().x;
    srcRectangle.y = p_entity.getCurrentFrame().y;
    srcRectangle.w = p_entity.getCurrentFrame().w;
    srcRectangle.h = p_entity.getCurrentFrame().h;

    dstRectangle.x = p_entity.getX();
    dstRectangle.y = p_entity.getY();
    dstRectangle.w = p_entity.getCurrentFrame().w;
    dstRectangle.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &srcRectangle, &dstRectangle);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}
