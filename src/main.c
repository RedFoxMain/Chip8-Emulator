#include <stdio.h>
#include "cpu.h"
#include "display.h"

int main(int argc, char* argv[]) {
	display_config_t config = { 200, 300, DISPLAY_WIDTH * 10, DISPLAY_HEIGHT * 10, 0 };
	display_t display;

	if (initDisplay(&display, config)) {
		
		cpu_t cpu;
		createCPU(&cpu);
		size_t size = 0;
		const char* file = "../../../TestROMs/BLINKY";
		loadProgram(&cpu, readFromFile(file, &size), size);
		execute(&cpu);
		//createDisplay(&display);
	}
	return 0;
}