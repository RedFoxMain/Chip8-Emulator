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
	memset(&cpu->memory[0], font, sizeof(font));
	cpu->pc = 0x200;
	cpu->spt = 0;
}

void loadProgram(cpu_t* cpu, uint8_t* program, size_t size) {
	memcpy(cpu->memory + START_ADDRESS, program, size);
}

void execute(cpu_t* cpu) {
	getInstr(cpu);
	switch ((cpu->instr.op_code >> 12) & 0x0F) {
		case 0x02:
			printf("Instr 2\n");
			break;
	}
}

void getInstr(cpu_t* cpu) {
	cpu->instr.op_code = (cpu->memory[cpu->pc] << 8) | cpu->memory[cpu->pc + 1];
	cpu->pc += 2;
	cpu->instr.nnn = cpu->instr.op_code & 0x0FFF;
	cpu->instr.nn = cpu->instr.op_code & 0x0FF;
	cpu->instr.n = cpu->instr.op_code & 0x0F;
	cpu->instr.x = (cpu->instr.op_code >> 8) & 0x0F;
	cpu->instr.y = (cpu->instr.op_code >> 4) & 0x0F;
}