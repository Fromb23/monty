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

	if (argc != 2)
	{
		write(2, "USAGE: ", 7);
		write(2, argv[0], _strlen(argv[0]));
		write(2, "\n", 1);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		write(2, "Error: Can't open file ", 23);
		write(2, argv[1], _strlen(argv[1]));
		write(2, "\n", 1);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		lineNumber++;
		len = _strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[--len] = '\0';

		processBuffer(buffer, lineNumber, &myStack, instructions);
	}
	fclose(file);
	free_malloc(&myStack);

	return (0);
}
