#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>

#include "globals.hpp"
#include "cliflags.hpp"

int main(int argc, char** argv) {
    #if TRACING
    Globals::Logger.EnableTracing();
    #endif

    if (argc < Globals::MINIMUM_ARGUMENT_COUNT) {
        Globals::Logger.Log(ERROR, "usage: ./%s -f <filepath>", PROJECT_NAME_STR);
        return 1;
    } else {
        CliArgs::InitalizeFlags(argc, argv);
    }

    if (Globals::FilePath == "") {
        Globals::Logger.Log(ERROR, "Unsupported File Format");
        return 1;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) { 
        Globals::Logger.Log(ERROR, "SDL could not initialize: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
            "Hello World",
            800,
            600,
            SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        Globals::Logger.Log(ERROR, "Window could not be created: %s", SDL_GetError()); 
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
