link_compile_commands: build
	ln -s build/compile_commands.json .

.PHONY: run
run: build
	SDL_VIDEODRIVER=x11 ./build/cpp-image-viewer

.PHONY: build
build:
	cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

