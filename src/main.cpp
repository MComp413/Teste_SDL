#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include "Utils.hpp"

#define GRASS_SQUARE_SIZE 32

using namespace std;

int main(int argc, char* args[])
{
    const float timeStep = 0.01f;
    
    bool gameRunning;
    float timeAccumulator, currentTime;
    SDL_Event event;
    SDL_Texture* grassTexture;
    std::vector<Entity> entityCollection;

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "SDL INIT VIDEO FAILED. SDL_ERROR :" << SDL_GetError() << endl;
    if(!(IMG_Init(IMG_INIT_PNG)))
        cout << "SDL IMG INIT FAILED. SDL_ERROR :" << SDL_GetError() << endl;

    RenderWindow gameWindow("GAME v0.1", 1280, 720);
    gameRunning = true;

    timeAccumulator = 0.0f;
    currentTime = utils::hireTimeInSeconds();

    grassTexture = gameWindow.loadTexture("res/gfx/ground_grass_1.png");
    entityCollection = {Entity(Vector2f(10, 10), grassTexture)};
    {
        Entity newGrassBlock(10+GRASS_SQUARE_SIZE, 10, grassTexture);
        entityCollection.push_back(newGrassBlock);
    }

    while(gameRunning)
    {
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        timeAccumulator += newTime - currentTime;
        currentTime = newTime;

        while(timeAccumulator >= timeStep)
        {
            while(SDL_PollEvent(&event))
            {
                if(event.type == SDL_QUIT)
                    gameRunning = false;
            }

            timeAccumulator -= timeStep;
        }

        const float percLeftInTimeAccumulator = timeAccumulator / timeStep;

        gameWindow.clear();

        for(Entity& e: entityCollection)
        {
            gameWindow.render(e);
        }

        gameWindow.display();

        int frameTicks = SDL_GetTicks() - startTicks;
        float minRefreshRate = 1000 / gameWindow.getRefreshRate();
        if(frameTicks < minRefreshRate)
            SDL_Delay(minRefreshRate - frameTicks);
    }

    gameWindow.cleanUp();
    SDL_Quit();

    return 0;
}