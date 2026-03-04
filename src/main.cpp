#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#include <skutil/skutilflagparser.hpp>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) { 
        std::cerr << "SDL could not initialize " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
            "Hello World",
            800,
            600,
            SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Window could not be created " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
