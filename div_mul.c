#include  "monty.h"

/**
 * divFunction - divides the second top element of the stack
 * by the top element
 * @stack: a pointer to the stack
 * @line_number: line number in the Monty file
 * Return: void
 */

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

/**
 * mulFunction - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number : the line number in the Monty file
 * Return: void
 */

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
