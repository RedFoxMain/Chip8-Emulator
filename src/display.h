#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdio.h>
#include "SDL.h"

typedef struct {
	int pos_x; int pos_y;
	int width; int height;
	Uint32 flags;
} display_config_t;

typedef struct {
	SDL_Window* wnd;
	SDL_Renderer* renderer;
} display_t;

bool initDisplay(display_t* display, display_config_t config);
void deleteDisplay(display_t* display);
#endif // !DISPLAY_H