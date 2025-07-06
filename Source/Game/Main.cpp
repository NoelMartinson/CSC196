#include <SDL3/SDL.h>
#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>

using namespace fox;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer); 

		for (int i = 0; i < 20; ++i) { // 20 random points
            Uint8 r = rand() % 256;
            Uint8 g = rand() % 256;
            Uint8 b = rand() % 256;
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);

            int x = static_cast<int>(random::getRandomFloat(0.0f, 1280.0f));
            int y = static_cast<int>(random::getRandomFloat(0.0f, 1024.0f));
            SDL_RenderPoint(renderer, x, y);
        }

		for (int i = 0; i < 10; ++i) { // 10 random lines
            Uint8 r = rand() % 256;
            Uint8 g = rand() % 256;
            Uint8 b = rand() % 256;
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);

            int x = static_cast<int>(random::getRandomFloat(0.0f, 1280.0f));
            int x2 = static_cast<int>(random::getRandomFloat(0.0f, 1280.0f));
            int y = static_cast<int>(random::getRandomFloat(0.0f, 1024.0f));
            int y2 = static_cast<int>(random::getRandomFloat(0.0f, 1024.0f));
            SDL_RenderLine(renderer, x, y, x2, y2); 
        }
        SDL_RenderPresent(renderer); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}