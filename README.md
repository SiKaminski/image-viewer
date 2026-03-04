Image Viewer

## About

This is a simple image viewer using SDL3 and C++

This does not use native SDL3 functions to load in file formats and render them, 
each file is manually loaded and parsed because I want to know more about how SDL works
and different file formats too

## Dependencies

- sdl3
- cmake
- gcc

## Build Commands

```
cmake -S . -B build
cmake --build build
```

## Issues to be solved

This is being developed on manjaro with KDE Plasma, if a window does not show up
with Wayland, force X11 with

```
SDL_VIDEODRIVER=x11 ./build/cpp-image-viewer
```

