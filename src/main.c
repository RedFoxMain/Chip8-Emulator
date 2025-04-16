#include <stdio.h>
#include "cpu.h"
#include "display.h"

int main(int argc, char* argv[]) {
	display_config_t config = { 200, 300, DISPLAY_WIDTH * 10, DISPLAY_HEIGHT * 10, 0 };

	cpu_t cpu;
	display_t display;

	initCPU(&cpu);
	initDisplay(&display, config);

	bool is_running = true;
	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: is_running = false; break;
			}
		}
	}

	deleteDisplay(&display);
	SDL_Quit();
	return 0;
}