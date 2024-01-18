#include "monty.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 **/

int main(int  argc, char *argv[])
{
	FILE *file;
	char buffer[1024];
	int lineNumber = 0, len;
	stack_t *myStack = NULL;
	instruction_t *instructions = get_instructions();
	char *first_char = strchr(buffer, '#');

	if (argc != 2)
	{
		free(instructions);
		fprintf(stderr, "USAGE: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		free(instructions);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		lineNumber++;
		len = _strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[--len] = '\0';
		first_char = strchr(buffer, '#');
		if (first_char != NULL && first_char == buffer)
			continue;

		processBuffer(buffer, lineNumber, &myStack, instructions);
	}
	fclose(file);
	free_malloc(&myStack);
	free(instructions);

	return (0);
}
