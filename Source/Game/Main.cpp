#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"

using namespace fox;

int main(int argc, char* argv[]) {
    fox::Time time;


    fox::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Fox Engine", 1280, 1024);


    SDL_Event e;
    bool quit = false;

    std::vector<fox::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024});
    }

    while (!quit) {
		time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        fox::vec2 speed{ 40.0f, 0.0f };
		float length = speed.Length();

        for (auto& star : stars) {
            star += speed * time.GetDeltaTime();

			if (star.x > 1280) star.x = 0;
			if (star.x < 0) star.x = 1280;

            renderer.SetColor(255, 255, 255);
            renderer.DrawPoint(star.x, star.y);
        }

        //for (int i = 0; i < 100; ++i) { // 10 random lines
        //    /*renderer.SetColor(fox::random::getRandomInt(255), fox::random::getRandomInt(255), fox::random::getRandomInt(255), fox::random::getRandomInt(255));
        //    renderer.DrawLine(fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024, fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024);*/
        //}

        //for (int i = 0; i < 500; ++i) { // 10 random points
        //    renderer.SetColor(fox::random::getRandomInt(255), fox::random::getRandomInt(255), fox::random::getRandomInt(255), fox::random::getRandomInt(255));
        //    renderer.DrawPoint(fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024);
        //}
        renderer.Present();
    }
    renderer.Shutdown();
    return 0;
};