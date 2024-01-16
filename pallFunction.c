#include "monty.h"

/**
 * pallFunction - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file (unused).
 **/

void pallFunction(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
