#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdio.h>
#include "SDL.h"
#include "cpu.h"


typedef struct {
	int pos_x; int pos_y;
	int width; int height;
	Uint32 flags;
} display_config_t;

typedef struct {
	SDL_Window* wnd;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	uint32_t* buffer;
} display_t;

bool initDisplay(display_t* display, display_config_t config);
void deleteDisplay(display_t* display);
void createDisplay(display_t* display);
void saveToBuffer(display_t* display);
#endif // !DISPLAY_H