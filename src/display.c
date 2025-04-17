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
	display->texture = SDL_CreateTexture(
		display->renderer,
		SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC,
		DISPLAY_WIDTH, DISPLAY_HEIGHT
	);
	if (!display->texture) {
		fprintf(stderr, "Could not create texture!\n");
		deleteDisplay(display);
		SDL_Quit();
		return false;
	}

	display->buffer = malloc(DISPLAY_HEIGHT * DISPLAY_WIDTH * sizeof(uint32_t));
	if (!display->buffer) {
		fprintf(stderr, "Could not create buffer!\n");
		deleteDisplay(display);
		SDL_Quit();
		return false;
	}
	memset(display->buffer, 0, DISPLAY_HEIGHT * DISPLAY_WIDTH * sizeof(uint32_t));
	return true;
}

void deleteDisplay(display_t* display) {
	SDL_DestroyWindow(display->wnd);
	SDL_DestroyRenderer(display->renderer);
	SDL_DestroyTexture(display->texture);
	free(display->buffer);
}

void createDisplay(display_t* display) {
	saveToBuffer(display);
	bool is_running = true;
	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: is_running = false; break;
			}
		}
	}
	SDL_Quit();
	deleteDisplay(display);
}

void saveToBuffer(display_t* display) {
	for (size_t i = 0; i < DISPLAY_HEIGHT * DISPLAY_WIDTH; ++i)
		display->buffer[i] = 0x0000ffff;
	SDL_UpdateTexture(display->texture, NULL, display->buffer, DISPLAY_WIDTH * sizeof(uint32_t));
	SDL_RenderClear(display->renderer);
	SDL_RenderCopy(display->renderer, display->texture, NULL, NULL);
	SDL_RenderPresent(display->renderer);
}