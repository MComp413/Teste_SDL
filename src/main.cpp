#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;

int main(int argc, char* args[])
{
    bool gameRunning;
    SDL_Event event;
    SDL_Texture* grassTexture;

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "SDL INIT VIDEO FAILED. SDL_ERROR :" << SDL_GetError() << endl;
    if(!(IMG_Init(IMG_INIT_PNG)))
        cout << "SDL IMG INIT FAILED. SDL_ERROR :" << SDL_GetError() << endl;

    RenderWindow gameWindow("GAME v0.1", 1280, 720);
    gameRunning = true;

    grassTexture = gameWindow.loadTexture("res/gfx/ground_grass_1.png");
    Entity platform0(10, 10, grassTexture);

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }

        gameWindow.clear();
        gameWindow.render(platform0);
        gameWindow.display();
    }

    gameWindow.cleanUp();
    SDL_Quit();

    return 0;
}