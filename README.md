CPP Image Viewer

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
