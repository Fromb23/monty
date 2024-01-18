#include "monty.h"

/**
 * free_malloc - Frees the memory allocated for a stack
 * @head: Pointer to the head of the stack
 **/

void free_malloc(stack_t **head)
{
	stack_t *current_node = *head, *temp_node;

	if (current_node == NULL)
	{
		return;
	}
	else
	{
		while (current_node != NULL)
		{
			temp_node = current_node->next;
			free(current_node);
			current_node = temp_node;
		}
	}
	current_node = NULL;
}
