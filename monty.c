#include "monty.h"

extern instruction_t instructions[];

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
		printf("USAGE: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
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

	return (EXIT_SUCCESS);
}
