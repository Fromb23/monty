#include "monty.h"

/**
 * get_instructions - Array of Monty opcodes and corresponding functions.
 * Return: returns instruction_t on success
 **/
instruction_t *get_instructions(void)
{
	instruction_t *instructions;

	instructions = malloc(9 * sizeof(instruction_t));
	if (instructions == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instructions[0].opcode = "push";
	instructions[0].f = pullFunction;
	instructions[1].opcode = "pall";
	instructions[1].f = pallFunction;
	instructions[2].opcode = "pint";
	instructions[2].f = pintFunction;
	instructions[3].opcode = "pop";
	instructions[3].f = popFunction;
	instructions[4].opcode = "swap";
	instructions[4].f = swapFunction;
	instructions[5].opcode = "nop";
	instructions[5].f = nopFunction;
	instructions[6].opcode = "add";
	instructions[6].f = addFunction;
	instructions[7].opcode = "sub";
	instructions[7].f= subFunction;
	instructions[8].opcode = NULL;
	instructions[8].f = NULL;

	return (instructions);
}

/**
 * free_instructions - frees all space of array instruction
 * after used
 * @instructions: an array having opcodes and corresponding functions.
 **/

void free_instructions(instruction_t *instructions)
{
	free(instructions);
}
