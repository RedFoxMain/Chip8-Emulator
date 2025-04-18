#ifndef CPU_H
#define CPU_H

#define START_ADDRESS 0x200
#define MEMORY_SIZE 4096
#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define REGISTER_COUNT 16
#define STACK_DEPTH 16
#define KEYS_COUNT 16
#define FONT_SIZE 80

#include <stdio.h>
#include <stdint.h>
#include "SDL.h"

static const uint8_t key_map[KEYS_COUNT] = {
	SDLK_x, SDLK_1, SDLK_2, SDLK_3, SDLK_q, SDLK_w, SDLK_e,
	SDLK_a, SDLK_s, SDLK_z, SDLK_c, SDLK_4, SDLK_r, SDLK_f, SDLK_v 
};

// http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
// values from 0 to F in HEX format
static const uint8_t font[FONT_SIZE] = {
	0xF0, 0x90, 0x90, 0x90, 0xF0,
	0x20, 0x60, 0x20, 0x20, 0x70,
	0xF0, 0x10, 0xF0, 0x80, 0xF0,
	0xF0, 0x10, 0xF0, 0x10, 0xF0,
	0x90, 0x90, 0xF0, 0x10, 0x10,
	0xF0, 0x80, 0xF0, 0x10, 0xF0,
	0xF0, 0x80, 0xF0, 0x90, 0xF0,
	0xF0, 0x10, 0x20, 0x40, 0x40,
	0xF0, 0x90, 0xF0, 0x90, 0xF0,
	0xF0, 0x90, 0xF0, 0x10, 0xF0,
	0xF0, 0x90, 0xF0, 0x90, 0x90,
	0xE0, 0x90, 0xE0, 0x90, 0xE0,
	0xF0, 0x80, 0x80, 0x80, 0xF0,
	0xE0, 0x90, 0x90, 0x90, 0xE0,
	0xF0, 0x80, 0xF0, 0x80, 0xF0,
	0xF0, 0x80, 0xF0, 0x80, 0x80
};

typedef struct {
	uint16_t op_code;
	uint16_t nnn;
	uint8_t nn;
	uint8_t n;
	uint8_t x;
	uint8_t y;
} instruction_t;

typedef struct {
	uint16_t memory[MEMORY_SIZE];
	uint16_t stack[STACK_DEPTH];
	uint8_t registers[REGISTER_COUNT];
	instruction_t instr;
	uint16_t pc;
	uint16_t spt;
	uint16_t I;
	uint8_t sound_timer;
	uint8_t delay_timer;
} cpu_t;

uint8_t* readFromFile(const char* file_name, size_t* size);
void createCPU(cpu_t* cpu);
void loadProgram(cpu_t* cpu, uint8_t* program, size_t size);
void execute(cpu_t* cpu);
void getInstr(cpu_t* cpu);
#endif // !CPU_H