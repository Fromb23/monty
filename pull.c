#include "monty.h"

/**
 * pullFunction - Adds a new node with a given value to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 **/

void pullFunction(stack_t **stack, unsigned int line_number)
{
	char *value;
	int intValue;
	stack_t *new_node;

	value = custom_strtok(NULL, " ");

	if (value == NULL || !isInteger(value))
	{
		printf("L %u: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	intValue = atoi(value);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = intValue;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
