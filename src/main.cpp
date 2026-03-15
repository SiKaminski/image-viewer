#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

#include "globals.hpp"
#include "cliflags.hpp"

void cleanup()
{
    // SDL_DestroyTexture(texture);
    // SDL_RenderPresent(renderer);
    // SDL_DestroyWindow(window);
    SDL_Quit();
}

int initSDL()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) { 
        Globals::Logger.Log(ERROR, "SDL could not initialize: %s", SDL_GetError());
        return -1;
    }

    Uint64 windowFlag = SDL_WINDOW_RESIZABLE;
    if (!Globals::MAXIMUM_WINDOW_HEIGHT && !Globals::MAXIMUM_WINDOW_WIDTH)
        windowFlag = SDL_WINDOW_FULLSCREEN;

    SDL_Window* window = SDL_CreateWindow(
        PROJECT_NAME_STR,
        Globals::MINIMUM_WINDOW_WIDTH,
        Globals::MINIMUM_WINDOW_HEIGHT,
        windowFlag
    );

    if (!window) {
        Globals::Logger.Log(ERROR, "Window could not be created: %s", SDL_GetError()); 
        SDL_Quit();
        return -1;
    }

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    // SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);

    // bool running = true;
    // SDL_Event event;

    // while (running) {
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_EVENT_QUIT)
    //             running = false;
    //     }

    //     void* pixels;
    //     int pitch;

    //     SDL_LockTexture(texture, nullptr, &pixels, &pitch);
    //     Uint32* buffer = static_cast<Uint32*>(pixels);

    //     buffer[300 * (pitch / 4) + 400] = 0x00FF00FF;
    //     // for (int y = 0; y < 300; ++y) {
    //     //     for (int x = 0; x < 400; ++x) {
    //     //     }
    //     // }

    //     SDL_UnlockTexture(texture);
    //     SDL_RenderClear(renderer);
    //     SDL_RenderTexture(renderer, texture, nullptr, nullptr);
    //     SDL_RenderPresent(renderer);
    // }
  
}

int main(int argc, char** argv) 
{
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

    int status = initSDL();
    if (!status)
      return status;

    cleanup();
    return 0;
}
