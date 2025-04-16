#include "cpu.h"

void initCPU(cpu_t* cpu) {
	memset(cpu, 0, sizeof(cpu_t));
	cpu->pc = START_ADDRESS;
	cpu->spt = -1;
}