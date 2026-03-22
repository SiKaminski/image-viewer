Image Viewer

## About

This is a simple image viewer using SDL3 and C++

This does not use native SDL3 functions to load in file formats and render them, 
each file is manually loaded and parsed because I want to know more about how SDL works
and different file formats too

## Dependencies

- sdl3
- cmake
- make
- gcc

## Build Commands

```
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DENABLE_TRACING=1
cmake --build build
SDL_VIDEODRIVER=x11 ./build/image-viewer -f samples/jarvis.bmp
```

## Issues to be solved

This is being developed on manjaro with KDE Plasma, if a window does not show up
with Wayland, force X11 with
