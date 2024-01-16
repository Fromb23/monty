#include "monty.h"

/**
 * swapFunction - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 **/

void swapFunction(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
