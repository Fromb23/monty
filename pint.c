#include "monty.h"

/**
 * pintFunction - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 **/

void pintFunction(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
