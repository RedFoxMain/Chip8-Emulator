#include "display.h"

bool initDisplay(display_t* display, display_config_t config) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "SDL Error! %s\n", SDL_GetError());
		return false;
	}
	display->wnd = SDL_CreateWindow(
		"Chip8 Emulator", 
		config.pos_x, config.pos_y, 
		config.width, config.height, config.flags
	);
	if (!display->wnd) {
		fprintf(stderr, "Could not create window!\n");
		return false;
	}
	display->renderer = SDL_CreateRenderer(display->wnd, -1, 0);
	if (!display->renderer) {
		fprintf(stderr, "Could not create renderer!\n");
		return false;
	}
	return true;
}

void deleteDisplay(display_t* display) {
	SDL_DestroyWindow(display->wnd);
	SDL_DestroyRenderer(display->renderer);
}

void createDisplay(display_t* display) {
	bool is_running = true;
	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: is_running = false; break;
			}
		}
		update(display);
	}
	SDL_Quit();
	deleteDisplay(display);
}

void update(display_t* display) {
	
}