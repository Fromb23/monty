#include "monty.h"

void addFunction(stack_t **stack, unsigned int line_number)
{
	int value1, value2;

	if (*stack == NULL || (*stack)->next == NULL)
	{       
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}       
	value1 = (*stack)->n;
	value2 = (*stack)->next->n;

	(*stack)->next->n = value1 + value2;

	popFunction(stack, line_number);
}   

void subFunction(stack_t **stack, unsigned int line_number)
{
	int value1, value2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value1 = (*stack)->n;
	value2 = (*stack)->next->n;

	(*stack)->next->n = value2 - value1;

	popFunction(stack, line_number);
}
