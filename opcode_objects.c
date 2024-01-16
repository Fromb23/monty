#include "monty.h"

/**
 * instructions - Array of Monty opcodes and corresponding functions.
 **/

instruction_t instructions[] = {
	{"push", pullFunction},
	{"pall", pallFunction},
	{"pint", pintFunction},
	{"pop", popFunction},
	{"swap", swapFunction},
	{NULL, NULL}
};
