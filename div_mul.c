#include  "monty.h"

void divFunction(stack_t **stack, unsigned int line_number)
{
	int value1, value2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value1 = (*stack)->n;
	value2 = (*stack)->next->n;

	if (value1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = value2 / value1;

	popFunction(stack, line_number);
}

void mulFunction(stack_t **stack, unsigned int line_number)
{
	int value1, value2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value1 = (*stack)->n;
	value2 = (*stack)->next->n;

	(*stack)->next->n = value1 * value2;

	popFunction(stack, line_number);
}
