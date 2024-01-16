#include "monty.h"

/**
 * popFunction - Removes the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 **/

void popFunction(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
