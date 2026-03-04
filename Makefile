.PHONY: run
run: build
	SDL_VIDEODRIVER=x11 ./build/cpp-image-viewer

.PHONY: build
build:
	cmake -S . -B build
	cmake --build build

