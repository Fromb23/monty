#include "monty.h"

/**
 * processBuffer - Processes a buffer containing instructions.
 * @buffer: The input buffer.
 * @line_number: The current line number.
 * @stack: The stack.
 * @instructions: The array of instructions.
 **/

void processBuffer(char *buffer, int line_number, stack_t **stack, instruction_t instructions[])
{
	int i, found = 0;
	char *opcode;

	opcode = custom_strtok(buffer, " ");
	if (opcode == NULL)
		return;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		printf("L%u: unknown instruction \"%s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
