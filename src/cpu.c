#include "cpu.h"

uint8_t* readFromFile(const char* file_name, size_t* size) {
	FILE* file = fopen(file_name, "rb");
	if (file == NULL) {
		fprintf(stderr, "Could not open file: %s", file);
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	size_t file_size = (size_t)ftell(file);
	fseek(file, 0, SEEK_SET);

	*size = file_size;

	uint8_t* buffer = malloc(file_size);
	fread(buffer, sizeof(uint8_t), file_size, file);
	fclose(file);
	return buffer;
}

void createCPU(cpu_t* cpu) {
	memset(cpu, 0, sizeof(cpu_t));
	cpu->pc = START_ADDRESS;
	cpu->spt = -1;
}

void loadProgram(cpu_t* cpu, uint8_t* program, size_t size) {
	memcpy(cpu->memory + FONT_ADDRESS, program, size);
}

void execute(cpu_t* cpu) {
	uint16_t instruction = cpu->memory[cpu->pc];
	uint16_t oper = (instruction << 8) & 0xF000;
	switch (oper) {
		default:
			break;
	}
}